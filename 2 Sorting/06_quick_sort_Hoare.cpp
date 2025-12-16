#include <bits/stdc++.h>
using namespace std;

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

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int p = hoarePartition(arr, low, high);

        // NOTE: p is NOT the pivot index
        quickSort(arr, low, p);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int arr[] = {5, 7, 6, 9, 4, 8, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size - 1);

    for (int x : arr)
        cout << x << " ";
}