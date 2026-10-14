// In question 1, define a destructor to deallocates the memory.

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
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.getFront() << endl;

    return 0;
}