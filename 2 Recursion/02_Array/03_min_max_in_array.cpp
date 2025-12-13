#include <bits/stdc++.h>
using namespace std;

int minNumber(int *arr, int size)
{
    if (size == 1)
        return arr[0];

    return min(arr[size-1], minNumber(arr, size - 1));
}

int maxNumber(int *arr, int size)
{
    if (size == 1)
        return arr[0];

    return max(arr[size - 1], maxNumber(arr, size - 1));
}

//! These two versions shrinks by 1 each call → depth = n
//$ We can also do a divide-and-conquer approach with depth ≈ log n

int minNumber2(int* arr, int l, int r)
{
    if (l == r) return arr[l];

    int mid = (l + r) / 2;
    int left = minNumber2(arr, l, mid);
    int right = minNumber2(arr, mid + 1, r);
    return min(left, right);
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, -1};

    cout << "\nMinimum: " << minNumber(arr, sizeof(arr) / sizeof(arr[0]));
    cout << "\nMaximum: " << maxNumber(arr, sizeof(arr) / sizeof(arr[0]));
    cout << "\nDivide & Conquer Min: " << minNumber2(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
}