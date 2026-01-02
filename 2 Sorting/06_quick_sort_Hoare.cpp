#include <iostream>
using namespace std;

/*
$   Hoare Partition Scheme
    ---------------------
    - Chooses the first element as pivot
    - Uses two indices moving toward each other
    - Places elements <= pivot on the left
      and elements >= pivot on the right
    - DOES NOT guarantee pivot ends up in its final position

#   Returns an index 'partitionIndex' such that:
        [low .. partitionIndex]      <= pivot
        [partitionIndex+1 .. high]   >= pivot
*/

int hoarePartition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        // move i right until element >= pivot
        do {
            i++;
        } while (arr[i] < pivot);

        // move j left until element <= pivot
        do {
            j--;
        } while (arr[j] > pivot);

        // pointers crossed: partition done
        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

/*
    Note the recursive calls:
    - Pivot is NOT at its final position
    - So recursion includes partitionIndex
*/
void quickSort(int *arr, int low, int high)
{
    if (low >= high) //~ Base case: one or zero elements are already sorted
        return;

    int partitionIndex = hoarePartition(arr, low, high);

    // Important difference from Lomuto:
    // partitionIndex is INCLUDED in left recursion    
    quickSort(arr, low, partitionIndex);
    quickSort(arr, partitionIndex + 1, high);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {93, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    cout << "After sorting:  ";
    printArray(arr, size);
}