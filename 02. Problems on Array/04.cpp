// Define a function to search an element in the array


#include <iostream>
using namespace std;

int searchElement(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {10, 25, 30, 45, 50};
    int size = 5;

    int element = 30;

    int index = searchElement(arr, size, element);

    if (index != -1)
    {
        cout << "Element found at index: " << index;
    }
    else
    {
        cout << "Element not found";
    }

    return 0;
}