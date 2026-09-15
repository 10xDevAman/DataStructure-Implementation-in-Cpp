// In question 1, define a method to check if the array is full by returning true or false.


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

    // Destructor
    ~DynArray()
    {
        delete[] ptr;
    }
};

int main()
{
    DynArray arr(5);

    if (arr.isFull())
        cout << "Array is full";
    else
        cout << "Array is not full";

    return 0;
}