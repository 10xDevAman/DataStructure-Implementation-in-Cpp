// Define a class Queue with node type pointers front and rear as member variables. Implement queue using Singly linked list.

#include <iostream>
using namespace std;

class Queue
{
private:
    struct node
    {
        int data;
        node* next;
    };

    node* front;
    node* rear;
};

int main()
{
    Queue q;

    return 0;
}