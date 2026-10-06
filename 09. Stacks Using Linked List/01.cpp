// Define a class Stack with node type pointer top as member variable. Implement stack using linked list.

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
};

int main()
{
    Stack s;

    return 0;
}