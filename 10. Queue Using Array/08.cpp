// In question 1, define a method to check queue overflow

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
        if (isFull())
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
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }

        return ptr[rear];
    }

    // View front element
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }

        return ptr[front];
    }

    // Delete front element
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }

    // Check queue overflow
    bool isFull()
    {
        return rear == capacity - 1;
    }

    // Check whether queue is empty
    bool isEmpty()
    {
        return front == -1;
    }

    // Destructor
    ~Queue()
    {
        delete[] ptr;
    }
};

int main()
{
    Queue q(3);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    if (q.isFull())
    {
        cout << "Queue is full." << endl;
    }
    else
    {
        cout << "Queue is not full." << endl;
    }

    q.enqueue(40);

    return 0;
}