#include <bits/stdc++.h>
using namespace std;

int binarySearchI(int *arr, int target, int low, int high)
{
    while (low <= high)
    {
        //! CPU will cry for large numbers
        // int mid = (low + high) / 2;

        //! This approach gives wrong result when both, low and high, are odd numbers
        // int mid = low/2 + high/2

        int mid = low + (high - low) / 2; // low + ((high - low) / 2)

        if (target == arr[mid])
            return mid;

        if (target < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int binarySearchR(int *arr, int target, int low, int high)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (target == arr[mid])
        return mid;

    if (target < arr[mid])
        return binarySearchR(arr, target, low, mid - 1);
    else
        return binarySearchR(arr, target, mid + 1, high);
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int target = 10;
    
    cout << "Iterative At index: " << binarySearchI(arr, target, 0, size - 1) << endl;
    cout << "Recursive At index: " << binarySearchR(arr, target, 0, size - 1) << endl;
}