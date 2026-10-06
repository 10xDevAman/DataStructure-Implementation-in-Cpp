// In question 1, define a constructor to initialise member variable.

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