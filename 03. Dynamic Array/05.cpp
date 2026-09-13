// In question 1, define a method which returns the current capacity of the array. 


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

    // Return current capacity
    int getCapacity()
    {
        return capacity;
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

    cout << "Current capacity: " << arr.getCapacity();

    return 0;
}