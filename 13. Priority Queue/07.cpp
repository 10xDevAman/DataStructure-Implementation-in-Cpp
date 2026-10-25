// In question 1, define a destructor to deallocate the memory.

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

        // Insert at beginning if priority is highest
        if (start == NULL || priority < start->priority)
        {
            n->next = start;
            start = n;
            return;
        }

        // Find the correct position
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
        if (start == NULL)
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
        if (start == NULL)
        {
            cout << "Priority Queue is empty." << endl;
            return -1;
        }

        return start->data;
    }

    // Get highest priority number
    int getHighestPriorityNumber()
    {
        if (start == NULL)
        {
            cout << "Priority Queue is empty." << endl;
            return -1;
        }

        return start->priority;
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

    pq.insert(100, 3);
    pq.insert(200, 1);
    pq.insert(300, 2);

    cout << "Highest priority element: "
         << pq.getHighestPriorityElement() << endl;

    cout << "Highest priority number: "
         << pq.getHighestPriorityNumber() << endl;

    pq.deleteHighestPriority();

    return 0;
}