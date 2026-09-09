// In question 1, define a method to edit an element at specified index.


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
        if (lastIndex == capacity - 1)
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

    arr.edit(1, 25);

    return 0;
}