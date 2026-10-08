// In question 1, define a destructor to deallocates the memory.

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
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        node* temp = top;
        int item = temp->data;

        top = top->next;

        delete temp;

        return item;
    }

    // Destructor
    ~Stack()
    {
        while (top != NULL)
        {
            node* temp = top;
            top = top->next;

            delete temp;
        }
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    return 0;
}