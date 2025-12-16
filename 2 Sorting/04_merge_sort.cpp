#include <iostream>
using namespace std;

/*
$    Merges two sorted subarrays of arr[]
#    First subarray:  leftIndex  to midIndex
#    Second subarray: midIndex+1 to rightIndex
*/

void merge(int *arr, int low, int mid, int high)
{
    // Temporary array to store the merged result, vector is preferred here
    int tempSize = high - low + 1;
    int C[tempSize];    // using 'variable size declaration' is not a good practice in C++, better -> C[100]
    
    int left = low;
    int right = mid + 1;
    int k = 0;

    // Compare elements from both subarrays and push the smaller one into temp
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])    //! '<=' will keep the algorithm stable, instead of only '<'
            C[k++] = arr[left++];
        else
            C[k++] = arr[right++];
    }

    while (left <= mid)
        C[k++] = arr[left++];
    
    while (right <= high)
        C[k++] = arr[right++];

    // Copy the merged elements back into the original array starting from index 'low'        
    for (int p = low, q = 0; p <= high && q < tempSize; p++, q++)
        arr[p] = C[q];
}

void mergeSort(int *arr, int low, int high)
{
    if (low >= high)    //$ Base case: one or zero elements are already sorted
        return;

    int mid = low + (high - low) / 2;

    //$ Recursively sort both halves
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);     //$ Merge the sorted halves - Merge Subarrays
}

//~ Iterative (bottom-up) merge sort
void mergeSortI(int *arr, int size)
{
    //$ currentSize represents the size of subarrays to be merged
    // It starts from 1 (single elements) and doubles every pass: 1 -> 2 -> 4 -> 8 -> ...
    for (int currentSize = 1; currentSize < size; currentSize = currentSize * 2)
    {
        //$ leftStart is the starting index of the left subarray
        // We move in steps of 2 * currentSize because we merge two adjacent subarrays of size currentSize at a time
        for (int low = 0; low < size - 1; low = low + (2 * currentSize))
        {
            //$ mid marks the end of the left subarray
            int mid = low + currentSize - 1;
            if (mid >= size)
                mid = size - 1;
            // Normally: mid = leftStart + currentSize - 1
            // But if currentSize goes beyond array bounds, we clamp mid to the last valid index                

            //$ rightEnd marks the end of the right subarray         
            int high = low + (2 * currentSize) - 1;
            if (high >= size)
                high = size - 1;
            // Normally: rightEnd = leftStart + 2*currentSize - 1
            // For arrays whose size is not a power of two, this may go past the array boundary, so we clamp it   

            //$ Merge only if there is a valid right subarray.
            // If mid == rightEnd, it means there is no second subarray to merge (only leftover elements), so we skip merging.
            if (mid < high)
                merge(arr, low, mid, high);
        }
    }
}

//~ Iterative (bottom-up) merge sort
// Easy to understand, but poor design (Extra merge after loop completes etc.)
void mergeSortI2(int arr[], int size)
{
    int listSize;
    for (listSize = 2; listSize <= size ; listSize = listSize * 2)
    {
        for (int i = 0; i + listSize - 1 < size; i = i + listSize)
        {
            int low = i;
            int high = i + listSize - 1;
            int mid = low + high / 2;
            merge(arr, low, mid, high);
        }
    }

    if (listSize / 2 < size)    // For merging left over elements if size is not power of 2 (size = 9)
        merge(arr, 0, listSize/2, size-1);
    //! Correct iterative merge sort should naturally handle leftovers
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

    // mergeSort(arr, 0, size - 1);
    mergeSortI(arr, size);

    cout << "After sorting:  ";
    printArray(arr, size);
}