#include <bits/stdc++.h>
using namespace std;

int lomutoPartition(int *arr, int low, int high)
{
    int pivot = arr[high];   // pivot is last element
    int i = low - 1;         // boundary for elements <= pivot

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // place pivot in its final position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int p = lomutoPartition(arr, low, high);

        // pivot is now in final position
        quickSort(arr, low, p - 1);
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