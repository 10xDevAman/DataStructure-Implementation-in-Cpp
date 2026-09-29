// In question 1, define a method to peek top element of the stack.

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
        // Check if stack is empty
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
            return -1;
        }

        return ptr[top];
    }
};

int main()
{
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;

    return 0;
}