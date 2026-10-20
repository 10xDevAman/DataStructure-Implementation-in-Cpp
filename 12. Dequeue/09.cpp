// In question 1, define a destructor to deallocate the memory.

#include <iostream>
using namespace std;

class Deque
{
private:
    struct node
    {
        int data;
        node* prev;
        node* next;
    };

    node* front;
    node* rear;

public:
    // Constructor
    Deque()
    {
        front = NULL;
        rear = NULL;
    }

    // Insert element at front
    void insertFront(int data)
    {
        node* n = new node;

        n->data = data;
        n->prev = NULL;
        n->next = front;

        if (front == NULL)
        {
            front = n;
            rear = n;
        }
        else
        {
            front->prev = n;
            front = n;
        }
    }

    // Insert element at rear
    void insertRear(int data)
    {
        node* n = new node;

        n->data = data;
        n->next = NULL;
        n->prev = rear;

        if (rear == NULL)
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

    // Delete front element
    void deleteFront()
    {
        if (front == NULL)
        {
            cout << "Deque Underflow" << endl;
            return;
        }

        node* temp = front;
        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }
        else
        {
            front->prev = NULL;
        }

        delete temp;
    }

    // Delete rear element
    void deleteRear()
    {
        if (rear == NULL)
        {
            cout << "Deque Underflow" << endl;
            return;
        }

        node* temp = rear;
        rear = rear->prev;

        if (rear == NULL)
        {
            front = NULL;
        }
        else
        {
            rear->next = NULL;
        }

        delete temp;
    }

    // Get front element
    int getFront()
    {
        if (front == NULL)
        {
            cout << "Deque is empty." << endl;
            return -1;
        }

        return front->data;
    }

    // Get rear element
    int getRear()
    {
        if (rear == NULL)
        {
            cout << "Deque is empty." << endl;
            return -1;
        }

        return rear->data;
    }

    // Destructor
    ~Deque()
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
    Deque d;

    d.insertRear(10);
    d.insertRear(20);
    d.insertRear(30);

    cout << "Front element: " << d.getFront() << endl;
    cout << "Rear element: " << d.getRear() << endl;

    return 0;
}