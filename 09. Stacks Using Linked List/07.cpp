// In question 1, define a copy constructor to implement deep copy.

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

    // Copy Constructor - Deep Copy
    Stack(const Stack& other)
    {
        top = NULL;

        if (other.top == NULL)
        {
            return;
        }

        // Copy nodes in reverse order using recursion
        copyNodes(other.top);
    }

private:
    void copyNodes(node* current)
    {
        if (current == NULL)
        {
            return;
        }

        copyNodes(current->next);

        node* n = new node;
        n->data = current->data;
        n->next = top;

        top = n;
    }

public:
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
    Stack s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    // Copy constructor
    Stack s2 = s1;

    cout << "Top element of copied stack: "
         << s2.peek() << endl;

    return 0;
}