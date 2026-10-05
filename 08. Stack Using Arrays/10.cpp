// In question 1, define a copy assignment operator to implement deep copy.

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

    // Copy Constructor - Deep Copy
    Stack(const Stack& other)
    {
        capacity = other.capacity;
        top = other.top;

        ptr = new int[capacity];

        for (int i = 0; i <= top; i++)
        {
            ptr[i] = other.ptr[i];
        }
    }

    // Push
    void push(int data)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        ptr[++top] = data;
    }

    // Peek
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return -1;
        }

        return ptr[top];
    }

    // Pop
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        return ptr[top--];
    }

    // Check Overflow
    bool isFull()
    {
        return top == capacity - 1;
    }

    // Check Underflow
    bool isEmpty()
    {
        return top == -1;
    }

    // Copy Assignment Operator - Deep Copy
    Stack& operator=(const Stack& other)
    {
        // Self-assignment check
        if (this == &other)
        {
            return *this;
        }

        // Deallocate existing memory
        delete[] ptr;

        // Copy capacity and top
        capacity = other.capacity;
        top = other.top;

        // Allocate new memory
        ptr = new int[capacity];

        // Copy elements
        for (int i = 0; i <= top; i++)
        {
            ptr[i] = other.ptr[i];
        }

        // Return current object
        return *this;
    }

    // Destructor
    ~Stack()
    {
        delete[] ptr;
    }
};

int main()
{
    Stack s1(5);

    s1.push(10);
    s1.push(20);
    s1.push(30);

    Stack s2(3);

    // Copy assignment operator
    s2 = s1;

    cout << "Top element of s2: " << s2.peek() << endl;

    return 0;
}