// In question 1, define a destructor to deallocate the memory of array.


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

    // Check whether array is full
    bool isFull()
    {
        return lastIndex == capacity - 1;
    }

    // Append a new element
    void append(int value)
    {
        if (isFull())
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
        if (isFull())
        {
            cout << "Array is full" << endl;
            return;
        }

        if (index < 0 || index > lastIndex + 1)
        {
            cout << "Invalid index" << endl;
            return;
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
        if (index < 0 || index > lastIndex)
        {
            cout << "Invalid index" << endl;
            return;
        }

        ptr[index] = value;
    }

    // Delete element at specified index
    void deleteElement(int index)
    {
        if (index < 0 || index > lastIndex)
        {
            cout << "Invalid index" << endl;
            return;
        }

        for (int i = index; i < lastIndex; i++)
        {
            ptr[i] = ptr[i + 1];
        }

        lastIndex--;
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

    // Count number of elements
    int count()
    {
        return lastIndex + 1;
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