// In question 1, define a method to check stack overflow


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
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
            return -1;
        }

        return ptr[top];
    }

    // Pop top element
    int pop()
    {
        if (top == -1)
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

    // Destructor
    ~Stack()
    {
        delete[] ptr;
    }
};

int main()
{
    Stack s(3);

    s.push(10);
    s.push(20);
    s.push(30);

    if (s.isFull())
    {
        cout << "Stack is full." << endl;
    }
    else
    {
        cout << "Stack is not full." << endl;
    }

    return 0;
}