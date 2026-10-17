// In question 1, define a method to insert a new element at the rear.

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
};

int main()
{
    Deque d;

    d.insertRear(10);
    d.insertRear(20);
    d.insertRear(30);

    return 0;
}