// In question 1, define a method to check stack underflow.

#include <iostream>
using namespace std;

class Stack
{
private:
    int capacity;
    int top;
    int* ptr;

public:
    // Parameterized Constructor
    Stack(int cap)
    {
        capacity = cap;
        top = -1;
        ptr = new int[capacity];
    }

    // Push a new element
    void push(int data)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        ptr[top] = data;
    }

    // Peek top element
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return -1;
        }

        return ptr[top];
    }

    // Pop top element
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        int item = ptr[top];
        top--;

        return item;
    }

    // Check Stack Overflow
    bool isFull()
    {
        return top == capacity - 1;
    }

    // Check Stack Underflow
    bool isEmpty()
    {
        return top == -1;
    }

    // Destructor
    ~Stack()
    {
        delete[] ptr;
    }
};

int main()
{
    Stack s(3);

    if (s.isEmpty())
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}