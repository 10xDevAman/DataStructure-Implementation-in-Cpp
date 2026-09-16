// In question 1, define a copy constructor to implement deep copy.


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

    // Copy Constructor - Deep Copy
    DynArray(const DynArray &obj)
    {
        capacity = obj.capacity;
        lastIndex = obj.lastIndex;

        ptr = new int[capacity];

        for (int i = 0; i <= lastIndex; i++)
        {
            ptr[i] = obj.ptr[i];
        }
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
    DynArray arr1(5);

    DynArray arr2 = arr1;

    cout << "Elements in arr2: " << arr2.count();

    return 0;
}