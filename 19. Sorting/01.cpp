// Define a function to implement bubble sort

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {5, 3, 8, 1, 2};
    int size = 5;

    bubbleSort(arr, size);

    cout << "Sorted array: ";

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}