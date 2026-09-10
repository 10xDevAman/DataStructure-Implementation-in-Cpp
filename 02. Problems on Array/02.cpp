// Define a function to find the greatest element in the array


#include <iostream>
using namespace std;

int greatestElement(int arr[], int size)
{
    int greatest = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > greatest)
        {
            greatest = arr[i];
        }
    }

    return greatest;
}

int main()
{
    int arr[] = {10, 45, 23, 67, 12};
    int size = 5;

    cout << "Greatest element: "
         << greatestElement(arr, size);

    return 0;
}