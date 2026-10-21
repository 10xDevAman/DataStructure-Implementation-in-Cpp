// In question 1, define a copy assignment operator to implement deep copy.

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

    // Copy constructor
    Deque(const Deque& other)
    {
        front = NULL;
        rear = NULL;

        node* temp = other.front;

        while (temp != NULL)
        {
            insertRear(temp->data);
            temp = temp->next;
        }
    }

    // Copy assignment operator
    Deque& operator=(const Deque& other)
    {
        if (this == &other)
        {
            return *this;
        }

        // Delete existing nodes
        while (front != NULL)
        {
            node* temp = front;
            front = front->next;
            delete temp;
        }

        rear = NULL;

        // Deep copy
        node* temp = other.front;

        while (temp != NULL)
        {
            insertRear(temp->data);
            temp = temp->next;
        }

        return *this;
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
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
            return -1;
        }

        return front->data;
    }

    // Get rear element
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
            return -1;
        }

        return rear->data;
    }

    // Check whether Deque is empty
    bool isEmpty()
    {
        return front == NULL;
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
    Deque d1;

    d1.insertRear(10);
    d1.insertRear(20);
    d1.insertRear(30);

    Deque d2;

    d2.insertRear(100);
    d2.insertRear(200);

    // Copy assignment operator called
    d2 = d1;

    cout << "Front of d1: " << d1.getFront() << endl;
    cout << "Front of d2: " << d2.getFront() << endl;

    d2.deleteFront();

    cout << "Front of d2 after deletion: "
         << d2.getFront() << endl;

    cout << "Front of d1 after deletion in d2: "
         << d1.getFront() << endl;

    return 0;
}