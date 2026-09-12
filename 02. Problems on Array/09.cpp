// Define a function to find the second largest element in the array. 


#include <iostream>
#include <climits>
using namespace std;

int secondLargest(int arr[], int size)
{
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

int main()
{
    int arr[] = {10, 50, 30, 40, 20};
    int size = 5;

    cout << "Second largest element: "
         << secondLargest(arr, size);

    return 0;
}