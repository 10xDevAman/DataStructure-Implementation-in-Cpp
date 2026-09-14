// In question 1, define a method to append a new element in the array


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
        int newCapacity = capacity * 2;

        int *temp = new int[newCapacity];

        // Copy existing elements
        for (int i = 0; i <= lastIndex; i++)
        {
            temp[i] = ptr[i];
        }

        // Deallocate old array
        delete[] ptr;

        // Point ptr to new array
        ptr = temp;

        // Update capacity
        capacity = newCapacity;
    }

    // Append a new element
    void append(int value)
    {
        // If array is full, double its capacity
        if (lastIndex == capacity - 1)
        {
            doubleArray();
        }

        lastIndex++;
        ptr[lastIndex] = value;
    }

    // Destructor
    ~DynArray()
    {
        delete[] ptr;
    }
};

int main()
{
    DynArray arr(3);

    arr.append(10);
    arr.append(20);
    arr.append(30);
    arr.append(40);

    return 0;
}