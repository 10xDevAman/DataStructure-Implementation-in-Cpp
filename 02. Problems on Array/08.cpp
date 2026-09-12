// Define a function to remove duplicate elements in the array. 


#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int size)
{
    int newSize = 0;

    for (int i = 0; i < size; i++)
    {
        bool isDuplicate = false;

        // Check if current element already exists
        for (int j = 0; j < newSize; j++)
        {
            if (arr[i] == arr[j])
            {
                isDuplicate = true;
                break;
            }
        }

        // Add element if it is not duplicate
        if (!isDuplicate)
        {
            arr[newSize] = arr[i];
            newSize++;
        }
    }

    return newSize;
}

int main()
{
    int arr[] = {10, 20, 10, 30, 20, 40, 30};
    int size = 7;

    size = removeDuplicates(arr, size);

    cout << "Array after removing duplicates: ";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}