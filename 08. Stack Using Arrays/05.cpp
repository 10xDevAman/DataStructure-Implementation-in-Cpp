// In question 1, define a method to pop the top element of the stack.

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
        if (top == capacity - 1)
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
        // Check for Stack Underflow
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        // Store top element
        int item = ptr[top];

        // Decrease top
        top--;

        // Return removed element
        return item;
    }
};

int main()
{
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Popped element: " << s.pop() << endl;

    return 0;
}