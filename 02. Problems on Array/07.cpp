// Define a function to rotate an array towards right by one position.


#include <iostream>
using namespace std;

void rotateRight(int arr[], int size)
{
    // Store the last element
    int lastElement = arr[size - 1];

    // Shift elements towards right
    for (int i = size - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    // Put last element at first position
    arr[0] = lastElement;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    rotateRight(arr, size);

    cout << "Array after right rotation: ";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}