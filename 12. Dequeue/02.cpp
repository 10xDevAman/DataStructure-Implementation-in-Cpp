// In question 1, define a constructor to initialise member variables

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

public:
    // Constructor
    Deque()
    {
        front = NULL;
        rear = NULL;
    }
};

int main()
{
    Deque d;

    return 0;
}