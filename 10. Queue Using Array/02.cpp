// In question 1, define a parameterzied constructor to initialise member variables.

#include <iostream>
using namespace std;

class Queue
{
private:
    int capacity;
    int front;
    int rear;
    int* ptr;

public:
    // Parameterized constructor
    Queue(int cap)
    {
        capacity = cap;
        front = -1;
        rear = -1;
        ptr = new int[capacity];
    }
};

int main()
{
    Queue q(5);

    return 0;
}