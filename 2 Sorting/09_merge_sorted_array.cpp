#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int *arr1, int size1, int *arr2, int size2, int i, int j, int k)
{
    //$ This return statement would probably go to base conditions (i == size1) or (j == size2)
    if(i == size1 && j == size2) return;

    if(i == size1)
    {
        // copy all remaining elements of arr2
        arr[k] = arr2[j];
        merge(arr, arr1, size1, arr2, size2, i, j + 1, k + 1);
        return;
    }
    if (j == size2)
    {
        // copy all remaining elements of arr1
        arr[k] = arr1[i];
        merge(arr, arr1, size1, arr2, size2, i + 1, j, k + 1);
        return;
    }

    if (arr1[i] < arr2[j])
    {
        arr[k] = arr1[i];
        merge(arr, arr1, size1, arr2, size2, i + 1, j, k + 1);
    }
    else
    {
        arr[k] = arr2[j];
        merge(arr, arr1, size1, arr2, size2, i, j + 1, k + 1);
    }
}

int main()
{
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr[10] = {0};

    merge(arr, arr1, size1, arr2, size2, 0, 0, 0);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}