// In question 1, define a method to push a new element on to the Stack.

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

    // Push a new element onto the stack
    void push(int data)
    {
        // Create a new node
        node* n = new node;

        // Store data
        n->data = data;

        // Link new node with current top
        n->next = top;

        // Make new node the top
        top = n;
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