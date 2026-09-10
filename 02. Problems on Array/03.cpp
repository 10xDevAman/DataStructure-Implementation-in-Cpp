// Define a function to find the smallest element in the array


#include <iostream>
using namespace std;

int smallestElement(int arr[], int size)
{
    int smallest = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }

    return smallest;
}

int main()
{
    int arr[] = {10, 45, 23, 67, 12};
    int size = 5;

    cout << "Smallest element: "
         << smallestElement(arr, size);

    return 0;
}