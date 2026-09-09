// In question 1, define a method to append a new element in the array 


#include <iostream>
using namespace std;

class Array
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    // Parameterized Constructor
    Array(int size)
    {
        capacity = size;
        lastIndex = -1;
        ptr = new int[capacity];
    }

    // Check whether array is empty
    bool isEmpty()
    {
        return lastIndex == -1;
    }

    // Append a new element
    void append(int value)
    {
        if (lastIndex == capacity - 1)
        {
            cout << "Array is full" << endl;
            return;
        }

        lastIndex++;
        ptr[lastIndex] = value;
    }

    // Destructor
    ~Array()
    {
        delete[] ptr;
    }
};

int main()
{
    Array arr(5);

    arr.append(10);
    arr.append(20);
    arr.append(30);

    return 0;
}