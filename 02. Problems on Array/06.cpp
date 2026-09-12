// Define a function to calculate average of all the elements of an array. 


#include <iostream>
using namespace std;

double calculateAverage(int arr[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }

    return (double)sum / size;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    cout << "Average of all elements: "
         << calculateAverage(arr, size);

    return 0;
}