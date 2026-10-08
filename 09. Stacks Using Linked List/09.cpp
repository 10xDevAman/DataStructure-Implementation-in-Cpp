// Define a method to reverse a stack.

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
    Stack()
    {
        top = NULL;
    }

    Stack(const Stack& other)
    {
        top = NULL;
        copyNodes(other.top);
    }

    Stack& operator=(const Stack& other)
    {
        if (this == &other)
        {
            return *this;
        }

        while (top != NULL)
        {
            node* temp = top;
            top = top->next;
            delete temp;
        }

        copyNodes(other.top);

        return *this;
    }

    void push(int data)
    {
        node* n = new node;

        n->data = data;
        n->next = top;

        top = n;
    }

    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty." << endl;
            return -1;
        }

        return top->data;
    }

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

    void reverse()
    {
        if (top == NULL || top->next == NULL)
        {
            return;
        }

        node* prev = NULL;
        node* current = top;
        node* next = NULL;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        top = prev;
    }

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

    // Before reverse:
    // Top -> 30 -> 20 -> 10

    s.reverse();

    // After reverse:
    // Top -> 10 -> 20 -> 30

    cout << s.peek() << endl;

    return 0;
}