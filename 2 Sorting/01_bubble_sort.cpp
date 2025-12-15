#include <iostream>
using namespace std;

/*
$   Bubble Sort Algorithm
    ---------------------
    Repeatedly compares adjacent elements and swaps them
    if they are in the wrong order.

#   Time Complexity:
        - Best Case: O(n)  (already sorted, with optimization)
        - Average:   O(n^2)
        - Worst:     O(n^2)

#   Space Complexity:
        - O(1) (in-place)
*/

void bubbleSort(int arr[], int size)
{
    // Outer loop controls the number of passes
    for (int pass = 0; pass < size - 1; pass++)
    {
        bool didSwap = false; // Optimization flag

        // Inner loop compares adjacent elements
        //! After each pass, the largest element is guaranteed to be at the end
        for (int index = 0; index < size - pass - 1; index++)
        {
            if (arr[index] > arr[index + 1])
            {
                // Swap adjacent elements
                swap(arr[index], arr[index + 1]);
                didSwap = true;
            }
        }

        // If no swaps occurred, array is already sorted
        if (!didSwap)
            break;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    printArray(arr, size);

    bubbleSort(arr, size);

    cout << "After sorting:  ";
    printArray(arr, size);
}