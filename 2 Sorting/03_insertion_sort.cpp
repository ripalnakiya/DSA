#include <iostream>
using namespace std;

/*
$   Insertion Sort Algorithm
    ------------------------
    Builds the final sorted array one element at a time.
    At each step, it takes the current element and inserts
    it into its correct position in the already-sorted left part.

#    Time Complexity:
        - Best Case:  O(n)    (already sorted)
        - Average:    O(n^2)
        - Worst Case: O(n^2)

#    Space Complexity:
        - O(1) (in-place)
*/

void insertionSort(int arr[], int size)
{
    //! Start from the second element because a single element is already considered sorted
    for (int currentIndex = 1; currentIndex < size; currentIndex++)
    {
        int element = arr[currentIndex];     //! Element to be inserted
        int previousIndex = currentIndex - 1;

        //! Shift elements of the sorted part to the right until the correct position for 'key' is found
        while (previousIndex >= 0 && element < arr[previousIndex])
        {
            arr[previousIndex + 1] = arr[previousIndex];
            previousIndex--;
        }

        //! Insert the key at its correct position
        arr[previousIndex + 1] = element;
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

    insertionSort(arr, size);

    cout << "After sorting:  ";
    printArray(arr, size);
}