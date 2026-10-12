// In question 1, define a constructor to initialise member variable.

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

public:
    // Constructor
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
};

int main()
{
    Queue q;

    return 0;
}