// Define a function to swap elements with specified indices in the array.


#include <iostream>
using namespace std;

void swapElements(int arr[], int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    swapElements(arr, 0, 3);

    cout << "Array after swapping: ";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}