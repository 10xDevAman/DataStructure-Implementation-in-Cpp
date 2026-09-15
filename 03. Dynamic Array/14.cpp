// In question 1, define a destructor to deallocate the memory of array.


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

    // Destructor
    ~DynArray()
    {
        delete[] ptr;
    }
};

int main()
{
    DynArray arr(5);

    cout << "Number of elements: " << arr.count();

    return 0;
}