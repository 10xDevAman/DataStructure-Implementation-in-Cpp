// Define a class Deque with node type pointers front and rear as member variables. Implement queue using doubly linked list.

#include <iostream>
using namespace std;

class Deque
{
private:
    struct node
    {
        int data;
        node* prev;
        node* next;
    };

    node* front;
    node* rear;
};

int main()
{
    Deque d;

    return 0;
}