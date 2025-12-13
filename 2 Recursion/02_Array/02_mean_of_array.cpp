#include <bits/stdc++.h>
using namespace std;

int findMean(int *arr, int size)
{
    if (size == 1)
        return arr[0];
    return (arr[size-1] + (findMean(arr, size-1) * (size-1))) / size;
}

int main()
{
    int arr[5] = {2,4,6,8,10};
    cout << findMean(arr, sizeof(arr)/sizeof(arr[0])); 
}