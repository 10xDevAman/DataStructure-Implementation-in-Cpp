// Define a function to implement modified bubble sort to achieve O(n) time complexity in best case.

#include <iostream>
using namespace std;

void modifiedBubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
            }
        }

        // If no swapping happened, array is sorted
        if (swapped == false)
            break;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;

    modifiedBubbleSort(arr, size);

    cout << "Sorted array: ";

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}