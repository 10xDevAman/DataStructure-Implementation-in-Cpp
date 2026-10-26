// In question 1, define a copy constructor to implement deep copy.

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

    // Copy constructor: deep copy
    PriorityQueue(const PriorityQueue& other)
    {
        start = NULL;

        node* temp = other.start;

        while (temp != NULL)
        {
            insert(temp->data, temp->priority);
            temp = temp->next;
        }
    }

    // Insert item according to priority
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
    PriorityQueue pq1;

    pq1.insert(100, 3);
    pq1.insert(200, 1);
    pq1.insert(300, 2);

    // Copy constructor called
    PriorityQueue pq2 = pq1;

    cout << "Highest priority element in pq1: "
         << pq1.getHighestPriorityElement() << endl;

    cout << "Highest priority element in pq2: "
         << pq2.getHighestPriorityElement() << endl;

    // Delete element from copied queue
    pq2.deleteHighestPriority();

    cout << "pq2 highest-priority element after deletion: "
         << pq2.getHighestPriorityElement() << endl;

    cout << "pq1 highest-priority element: "
         << pq1.getHighestPriorityElement() << endl;

    return 0;
}