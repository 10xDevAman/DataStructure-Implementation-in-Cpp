// In question 1, define a parameterised constructor to create an array of specified size.


#include <iostream>
using namespace std;

class Array
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    // Parameterized Constructor
    Array(int size)
    {
        capacity = size;
        lastIndex = -1;
        ptr = new int[capacity];
    }

    // Destructor
    ~Array()
    {
        delete[] ptr;
    }
};

int main()
{
    Array arr(5);

    return 0;
}