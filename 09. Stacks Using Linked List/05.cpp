// In question 1, define a method to pop the top element of the stack.

#include <iostream>
using namespace std;

class Stack
{
private:
    struct node
    {
        int data;
        node* next;
    };

    node* top;

public:
    // Constructor
    Stack()
    {
        top = NULL;
    }

    // Push a new element
    void push(int data)
    {
        node* n = new node;

        n->data = data;
        n->next = top;

        top = n;
    }

    // Peek top element
    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty." << endl;
            return -1;
        }

        return top->data;
    }

    // Pop top element
    int pop()
    {
        // Check for Stack Underflow
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        // Store top node
        node* temp = top;

        // Store data
        int item = temp->data;

        // Move top to next node
        top = top->next;

        // Delete old top node
        delete temp;

        // Return popped element
        return item;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Popped element: " << s.pop() << endl;

    return 0;
}