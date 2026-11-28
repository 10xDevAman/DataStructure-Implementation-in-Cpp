// Define a function to implement merge sort


#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int *left = new int[n1];
    int *right = new int[n2];

    // Copy elements into temporary arrays
    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];

    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    // Merge the two sorted arrays
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    // Copy remaining elements from left array
    while (i < n1)
        arr[k++] = left[i++];

    // Copy remaining elements from right array
    while (j < n2)
        arr[k++] = right[j++];

    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {5, 3, 8, 1, 2};
    int size = 5;

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}
