// In question 1, define a method to find an element in the array. Return index if the element found, otherwise return -1.


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

    // Count number of elements
    int count()
    {
        return lastIndex + 1;
    }

    // Find element
    int find(int value)
    {
        for (int i = 0; i <= lastIndex; i++)
        {
            if (ptr[i] == value)
                return i;
        }

        return -1;
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

    cout << "Index: " << arr.find(30);

    return 0;
}