// In question 1, define a method to count number of elements present in the queue.

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

    // Copy constructor
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

    // Copy assignment operator
    Queue& operator=(const Queue& other)
    {
        if (this == &other)
        {
            return *this;
        }

        while (front != NULL)
        {
            node* temp = front;
            front = front->next;
            delete temp;
        }

        rear = NULL;

        node* temp = other.front;

        while (temp != NULL)
        {
            enqueue(temp->data);
            temp = temp->next;
        }

        return *this;
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

    // Count elements
    int count()
    {
        int total = 0;
        node* temp = front;

        while (temp != NULL)
        {
            total++;
            temp = temp->next;
        }

        return total;
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

    cout << "Number of elements: " << q.count() << endl;

    q.dequeue();

    cout << "Elements after deletion: " << q.count() << endl;

    return 0;
}