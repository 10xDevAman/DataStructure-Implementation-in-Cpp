// In question 1, define a method to insert new item in the Priority Queue according to the priority number.

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

    // Insert item according to priority
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

        // Find the correct position
        node* temp = start;

        while (temp->next != NULL &&
               temp->next->priority <= priority)
        {
            temp = temp->next;
        }

        // Insert the new node
        n->next = temp->next;
        temp->next = n;
    }
};

int main()
{
    PriorityQueue pq;

    pq.insert(100, 3);
    pq.insert(200, 1);
    pq.insert(300, 2);
    pq.insert(400, 1);

    return 0;
}