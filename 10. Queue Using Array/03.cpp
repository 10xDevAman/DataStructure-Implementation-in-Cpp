// In question 1, define a method to insert a new element at the rear in the queue.

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
};

int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    return 0;
}