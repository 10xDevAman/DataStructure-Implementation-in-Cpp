// In question 1, define a copy assignment operator to implement deep copy.

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

    // Copy constructor
    Queue(const Queue& other)
    {
        capacity = other.capacity;
        front = other.front;
        rear = other.rear;

        ptr = new int[capacity];

        for (int i = front; i <= rear; i++)
        {
            ptr[i] = other.ptr[i];
        }
    }

    // Copy assignment operator
    Queue& operator=(const Queue& other)
    {
        if (this == &other)
        {
            return *this;
        }

        // Delete old memory
        delete[] ptr;

        // Copy properties
        capacity = other.capacity;
        front = other.front;
        rear = other.rear;

        // Allocate new array
        ptr = new int[capacity];

        // Deep copy active elements
        for (int i = front; i <= rear; i++)
        {
            ptr[i] = other.ptr[i];
        }

        return *this;
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

    // Check overflow
    bool isFull()
    {
        return rear == capacity - 1;
    }

    // Check underflow
    bool isEmpty()
    {
        return front == -1;
    }

    // Count elements
    int count()
    {
        if (isEmpty())
        {
            return 0;
        }

        return rear - front + 1;
    }

    // Destructor
    ~Queue()
    {
        delete[] ptr;
    }
};

int main()
{
    Queue q1(5);

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);

    Queue q2(3);

    q2.enqueue(100);
    q2.enqueue(200);

    // Copy assignment operator called
    q2 = q1;

    cout << "Front of q1: " << q1.getFront() << endl;
    cout << "Front of q2: " << q2.getFront() << endl;

    q2.dequeue();

    cout << "Front of q2 after deletion: "
         << q2.getFront() << endl;

    cout << "Front of q1 after q2 deletion: "
         << q1.getFront() << endl;

    return 0;
}