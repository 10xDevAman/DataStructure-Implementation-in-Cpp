// Define a function to implement insertion sort.


#include <iostream>
using namespace std;

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key to the right
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert key at its correct position
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {5, 3, 8, 1, 2};
    int size = 5;

    insertionSort(arr, size);

    cout << "Sorted array: ";

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}
