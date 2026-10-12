// In question 1, define a method to insert a new element at the rear in the queue.

#include <iostream>
using namespace std;

class Queue
{
private:
    struct node
    {
        int data;
        node* next;
    };

    node* front;
    node* rear;

public:
    // Constructor
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // Insert element at rear
    void enqueue(int data)
    {
        node* n = new node;

        n->data = data;
        n->next = NULL;

        if (front == NULL)
        {
            front = n;
            rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    return 0;
}