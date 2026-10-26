// In question 1, define a method to check if Priority Queue is empty

#include <iostream>
using namespace std;

class PriorityQueue
{
private:
    struct node
    {
        int data;
        int priority;
        node* next;
    };

    node* start;

public:
    // Constructor
    PriorityQueue()
    {
        start = NULL;
    }

    // Insert according to priority
    void insert(int data, int priority)
    {
        node* n = new node;

        n->data = data;
        n->priority = priority;
        n->next = NULL;

        // Insert at beginning
        if (start == NULL || priority < start->priority)
        {
            n->next = start;
            start = n;
            return;
        }

        // Find correct position
        node* temp = start;

        while (temp->next != NULL &&
               temp->next->priority <= priority)
        {
            temp = temp->next;
        }

        n->next = temp->next;
        temp->next = n;
    }

    // Delete highest-priority element
    void deleteHighestPriority()
    {
        if (isEmpty())
        {
            cout << "Priority Queue Underflow" << endl;
            return;
        }

        node* temp = start;
        start = start->next;

        delete temp;
    }

    // Get highest-priority element
    int getHighestPriorityElement()
    {
        if (isEmpty())
        {
            cout << "Priority Queue is empty." << endl;
            return -1;
        }

        return start->data;
    }

    // Get highest priority number
    int getHighestPriorityNumber()
    {
        if (isEmpty())
        {
            cout << "Priority Queue is empty." << endl;
            return -1;
        }

        return start->priority;
    }

    // Check whether Priority Queue is empty
    bool isEmpty()
    {
        return start == NULL;
    }

    // Destructor
    ~PriorityQueue()
    {
        while (start != NULL)
        {
            node* temp = start;
            start = start->next;
            delete temp;
        }
    }
};

int main()
{
    PriorityQueue pq;

    // Initially, queue is empty
    if (pq.isEmpty())
    {
        cout << "Priority Queue is empty." << endl;
    }

    pq.insert(100, 3);
    pq.insert(200, 1);
    pq.insert(300, 2);

    if (pq.isEmpty())
    {
        cout << "Priority Queue is empty." << endl;
    }
    else
    {
        cout << "Priority Queue is not empty." << endl;
    }

    pq.deleteHighestPriority();
    pq.deleteHighestPriority();
    pq.deleteHighestPriority();

    if (pq.isEmpty())
    {
        cout << "Priority Queue is empty after deletion." << endl;
    }

    return 0;
}