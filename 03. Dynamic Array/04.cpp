// In question 1, define a method halfArray() to decrease the size of the array by half of its size.


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

        for (int i = 0; i <= lastIndex; i++)
        {
            temp[i] = ptr[i];
        }

        delete[] ptr;

        ptr = temp;
        capacity = capacity * 2;
    }

    // Decrease the size of the array by half
    void halfArray()
    {
        int newCapacity = capacity / 2;

        // Ensure at least one block is available
        if (newCapacity < 1)
        {
            newCapacity = 1;
        }

        int *temp = new int[newCapacity];

        // Copy only elements that fit in the new array
        int newLastIndex = lastIndex;

        if (newLastIndex >= newCapacity)
        {
            newLastIndex = newCapacity - 1;
        }

        for (int i = 0; i <= newLastIndex; i++)
        {
            temp[i] = ptr[i];
        }

        delete[] ptr;

        ptr = temp;
        capacity = newCapacity;
        lastIndex = newLastIndex;
    }

    // Destructor
    ~DynArray()
    {
        delete[] ptr;
    }
};

int main()
{
    DynArray arr(10);

    arr.halfArray();

    return 0;
}