// In question 1, define a parameterized constructor to create an array of specified size.


#include <iostream>
using namespace std;

class DynArray
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    // Parameterized Constructor
    DynArray(int size)
    {
        capacity = size;
        lastIndex = -1;
        ptr = new int[capacity];
    }
};

int main()
{
    DynArray arr(5);

    return 0;
}