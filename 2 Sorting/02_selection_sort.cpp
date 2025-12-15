#include <iostream>
using namespace std;

/*
$   Selection Sort Algorithm
    ------------------------
    Repeatedly selects the smallest element from the unsorted part
    and moves it to the beginning.

#   Time Complexity:
        Best / Average / Worst: O(n^2)
#   Space Complexity:
        O(1) (in-place)
*/

void selectionSort(int arr[], int n)
{
    // Move the boundary of the unsorted subarray
    for (int currentIndex = 0; currentIndex < n - 1; currentIndex++)
    {
        int minIndex = currentIndex;

        // Find the minimum element in the remaining unsorted array
        for (int checkIndex = currentIndex + 1; checkIndex < n; checkIndex++)
        {
            if (arr[checkIndex] < arr[minIndex])
            {
                minIndex = checkIndex;
            }
        }

        // Swap the found minimum element with the first element
        if (minIndex != currentIndex)
        {
            swap(arr[currentIndex], arr[minIndex]);
        }
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
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    printArray(arr, size);

    selectionSort(arr, size);

    cout << "After sorting:  ";
    printArray(arr, size);
}