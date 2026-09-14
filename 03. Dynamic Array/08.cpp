// In question 1, define a method to insert a new element at specified index


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

        delete[] ptr;

        ptr = temp;
        capacity = newCapacity;
    }

    // Append a new element
    void append(int value)
    {
        if (lastIndex == capacity - 1)
        {
            doubleArray();
        }

        lastIndex++;
        ptr[lastIndex] = value;
    }

    // Insert element at specified index
    void insert(int index, int value)
    {
        // Check for valid index
        if (index < 0 || index > lastIndex + 1)
        {
            cout << "Invalid index" << endl;
            return;
        }

        // If array is full, double its capacity
        if (lastIndex == capacity - 1)
        {
            doubleArray();
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

    arr.insert(1, 15);

    return 0;
}