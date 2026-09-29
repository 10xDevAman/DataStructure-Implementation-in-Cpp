// In question 1, define a method to push a new element on to the Stack.

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

    // Push a new element onto the stack
    void push(int data)
    {
        // Check for stack overflow
        if (top == capacity - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        // Increment top and insert element
        top++;
        ptr[top] = data;
    }
};

int main()
{
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    return 0;
}