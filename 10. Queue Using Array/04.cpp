// In question 1, define a method to view rear element of the queue.

#include <iostream>
using namespace std;

class Queue
{
private:
    int capacity;
    int front;
    int rear;
    int* ptr;

public:
    // Parameterized constructor
    Queue(int cap)
    {
        capacity = cap;
        front = -1;
        rear = -1;
        ptr = new int[capacity];
    }

    // Insert element at rear
    void enqueue(int data)
    {
        if (rear == capacity - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        ptr[rear] = data;
    }

    // View rear element
    int getRear()
    {
        if (rear == -1)
        {
            cout << "Queue is empty." << endl;
            return -1;
        }

        return ptr[rear];
    }
};

int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Rear element: " << q.getRear() << endl;

    return 0;
}