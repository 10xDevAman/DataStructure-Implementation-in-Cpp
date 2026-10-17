// In question 1, define a method to insert a new element at the front

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
};

int main()
{
    Deque d;

    d.insertFront(10);
    d.insertFront(20);
    d.insertFront(30);

    return 0;
}