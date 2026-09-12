// Define a function to calculate sum of all the elements of an array. 


#include <iostream>
using namespace std;

int calculateSum(int arr[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }

    return sum;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    cout << "Sum of all elements: "
         << calculateSum(arr, size);

    return 0;
}