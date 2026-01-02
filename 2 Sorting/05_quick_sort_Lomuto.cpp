#include <iostream>
using namespace std;

/*
$   Lomuto Partition Scheme
    -----------------------
    - Chooses the last element as pivot
    - Rearranges the array so that:
        * Elements <= pivot are on the left
        * Elements  > pivot are on the right
    - Returns the final index of the pivot
*/

/*
# So while the loop is running, the invariant is:

[ low .. smallerElementIndex ]                  -> <= pivot
[ smallerElementIndex+1 .. currentIndex-1 ]     -> > pivot
[ currentIndex .. high-1 ]                      -> unknown
[ high ]                                        -> pivot (untouched)

# At the completion of partion function, Final state becomes:
[ low .. pivotIndex-1 ]                 -> <= pivot
[ pivotIndex ]                          -> pivot
[ pivotIndex+1 .. high ]                -> > pivot

Where, pivotIndex = smallerElementIndex + 1;
*/

int lomutoPartition(int *arr, int low, int high)
{
    int pivot = arr[high];   // pivot is last element
    int smallerElementIndex = low - 1;      // boundary for elements <= pivot

    for (int i = low; i < high; i++)
    {
        if (arr[i] <= pivot)
        {
            smallerElementIndex++;
            swap(arr[smallerElementIndex], arr[i]);
        }
    }

    // place pivot in its correct sorted position (final position)
    int pivotIndex = smallerElementIndex + 1;
    swap(arr[pivotIndex], arr[high]);
    return pivotIndex;
}

void quickSort(int *arr, int low, int high)
{
    if (low >= high) //~ Base case: one or zero elements are already sorted
        return;

    int pivotIndex  = lomutoPartition(arr, low, high);

    // 'pivot' is now in final position
    // Recursively sort elements before and after pivot
    quickSort(arr, low, pivotIndex  - 1);
    quickSort(arr, pivotIndex  + 1, high);
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

    quickSort(arr, 0, size - 1);

    cout << "After sorting:  ";
    printArray(arr, size);
}