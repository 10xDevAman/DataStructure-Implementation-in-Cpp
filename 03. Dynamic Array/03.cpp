// In question 1, define a method doubleArray() to increase the size of the array by double of its size.


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

    // Double the size of the array
    void doubleArray()
    {
        int *temp = new int[capacity * 2];

        // Copy existing elements
        for (int i = 0; i <= lastIndex; i++)
        {
            temp[i] = ptr[i];
        }

        // Delete old array
        delete[] ptr;

        // Point ptr to new array
        ptr = temp;

        // Update capacity
        capacity = capacity * 2;
    }

    // Destructor
    ~DynArray()
    {
        delete[] ptr;
    }
};

int main()
{
    DynArray arr(5);

    arr.doubleArray();

    return 0;
}