// In question 1, define a copy constructor to implement deep copy.

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

    // Copy constructor: deep copy
    Queue(const Queue& other)
    {
        front = NULL;
        rear = NULL;

        node* temp = other.front;

        while (temp != NULL)
        {
            enqueue(temp->data);
            temp = temp->next;
        }
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

    // View front element
    int getFront()
    {
        if (front == NULL)
        {
            cout << "Queue is empty." << endl;
            return -1;
        }

        return front->data;
    }

    // View rear element
    int getRear()
    {
        if (rear == NULL)
        {
            cout << "Queue is empty." << endl;
            return -1;
        }

        return rear->data;
    }

    // Delete front element
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue Underflow" << endl;
            return;
        }

        node* temp = front;
        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        delete temp;
    }

    // Destructor
    ~Queue()
    {
        while (front != NULL)
        {
            node* temp = front;
            front = front->next;
            delete temp;
        }

        rear = NULL;
    }
};

int main()
{
    Queue q1;

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);

    // Copy constructor called
    Queue q2 = q1;

    cout << "Front of q1: " << q1.getFront() << endl;
    cout << "Front of q2: " << q2.getFront() << endl;

    q2.dequeue();

    cout << "Front of q2 after deletion: "
         << q2.getFront() << endl;

    cout << "Front of q1 after deletion in q2: "
         << q1.getFront() << endl;

    return 0;
}