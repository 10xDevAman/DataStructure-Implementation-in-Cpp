// In question 1, define a method to get element at specified index.

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

    // Check whether array is full
    bool isFull()
    {
        return lastIndex == capacity - 1;
    }

    // Get element at specified index
    int get(int index)
    {
        if (index < 0 || index > lastIndex)
        {
            cout << "Invalid index" << endl;
            return -1;
        }

        return ptr[index];
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

    cout << "Element: " << arr.get(2);

    return 0;
}