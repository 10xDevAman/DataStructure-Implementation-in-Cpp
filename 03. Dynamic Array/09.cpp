// In question 1, define a method to edit an element at specified index.


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
        if (index < 0 || index > lastIndex + 1)
        {
            cout << "Invalid index" << endl;
            return;
        }

        if (lastIndex == capacity - 1)
        {
            doubleArray();
        }

        for (int i = lastIndex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }

        ptr[index] = value;
        lastIndex++;
    }

    // Edit element at specified index
    void edit(int index, int value)
    {
        // Check if index is valid
        if (index < 0 || index > lastIndex)
        {
            cout << "Invalid index" << endl;
            return;
        }

        // Update the element
        ptr[index] = value;
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

    arr.append(10);
    arr.append(20);
    arr.append(30);

    arr.edit(1, 25);

    return 0;
}