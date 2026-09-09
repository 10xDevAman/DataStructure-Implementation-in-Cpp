// In question 1, define a method to insert a new element at specified index


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

    // Insert element at specified index
    void insert(int index, int value)
    {
        // Check if array is full
        if (lastIndex == capacity - 1)
        {
            cout << "Array is full" << endl;
            return;
        }

        // Check for valid index
        if (index < 0 || index > lastIndex + 1)
        {
            cout << "Invalid index" << endl;
            return;
        }

        // Shift elements to the right
        for (int i = lastIndex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }

        // Insert new element
        ptr[index] = value;

        // Update lastIndex
        lastIndex++;
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
    arr.append(40);

    arr.insert(2, 25);

    return 0;
}