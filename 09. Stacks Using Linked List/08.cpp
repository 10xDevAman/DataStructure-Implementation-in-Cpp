// In question 1, define a copy assignment operator to implement deep copy. 

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

    // Helper function for deep copy
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
    // Constructor
    Stack()
    {
        top = NULL;
    }

    // Copy constructor
    Stack(const Stack& other)
    {
        top = NULL;
        copyNodes(other.top);
    }

    // Copy assignment operator
    Stack& operator=(const Stack& other)
    {
        // Self-assignment check
        if (this == &other)
        {
            return *this;
        }

        // Delete existing nodes
        while (top != NULL)
        {
            node* temp = top;
            top = top->next;
            delete temp;
        }

        // Deep copy
        copyNodes(other.top);

        return *this;
    }

    // Push
    void push(int data)
    {
        node* n = new node;

        n->data = data;
        n->next = top;

        top = n;
    }

    // Peek
    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty." << endl;
            return -1;
        }

        return top->data;
    }

    // Pop
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

    Stack s2;

    s2 = s1;   // Copy assignment operator called

    cout << s2.peek() << endl;

    return 0;
}