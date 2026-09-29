// In question 1, define a parameterzied constructor to initialise member variables. 

#include <iostream>
using namespace std;

class Stack
{
private:
    int capacity;
    int top;
    int* ptr;

public:
    // Parameterized Constructor
    Stack(int cap)
    {
        capacity = cap;
        top = -1;
        ptr = new int[capacity];
    }
};

int main()
{
    Stack s(5);

    return 0;
}