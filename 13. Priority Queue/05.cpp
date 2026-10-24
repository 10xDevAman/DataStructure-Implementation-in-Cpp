// In question 1, define a method to get highest priority element

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
};

int main()
{
    PriorityQueue pq;

    pq.insert(100, 3);
    pq.insert(200, 1);
    pq.insert(300, 2);

    cout << "Highest priority element: "
         << pq.getHighestPriorityElement() << endl;

    return 0;
}