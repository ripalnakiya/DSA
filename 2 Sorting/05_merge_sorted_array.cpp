#include <bits/stdc++.h>
using namespace std;

void merge(int *arrA, int sizeA, int *arrB, int sizeB, int *arr, int i, int j, int k)
{
    //$ This return statement would probably go to base conditions (i == sizeA) or (j == sizeB)
    if(i == sizeA && j == sizeB) return;

    if(i == sizeA)
    {
        // copy all remaining elements of arrB
        arr[k] = arrB[j];
        merge(arrA, sizeA, arrB, sizeB, arr, i, j + 1, k + 1);
        return;
    }
    if (j == sizeB)
    {
        // copy all remaining elements of arrA
        arr[k] = arrA[i];
        merge(arrA, sizeA, arrB, sizeB, arr, i + 1, j, k + 1);
        return;
    }

    if (arrA[i] <= arrB[j])
    {
        arr[k] = arrA[i];
        merge(arrA, sizeA, arrB, sizeB, arr, i + 1, j, k + 1);
    }
    else
    {
        arr[k] = arrB[j];
        merge(arrA, sizeA, arrB, sizeB, arr, i, j + 1, k + 1);
    }
}

int main()
{
    int arrA[] = {1, 3, 5};
    int arrB[] = {2, 4, 6};
    int sizeA = sizeof(arrA) / sizeof(arrA[0]);
    int sizeB = sizeof(arrB) / sizeof(arrB[0]);
    int arr[sizeA + sizeB];

    merge(arrA, sizeA, arrB, sizeB, arr, 0, 0, 0);

    for (int n : arr)
        cout << n << " ";
}