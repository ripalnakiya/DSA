#include <bits/stdc++.h>
using namespace std;

int findFirstI(int *arr, int target, int low, int high)
{
    int first = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (target == arr[mid])
        {   //$ If found the element, assume it's left most
            //$ And search if there exists another element on the left of current element
            first = mid;
            high = mid - 1;
            continue;   //# If we don't continue, value of low will change in else condition
        }

        if (target < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return first;
}

int findFirstR(int *arr, int target, int low, int high)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (target == arr[mid])
    {
        int left = findFirstR(arr, target, low, mid - 1);
        return (left == -1) ? mid : left;
    }

    if (target < arr[mid])
        return findFirstR(arr, target, low, mid - 1);
    else
        return findFirstR(arr, target, mid + 1, high);
}

int findLastI(int *arr, int target, int low, int high)
{
    int last = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (target == arr[mid])
        {   //$ If found the element, assume it's right most
            //$ And search if there exists another element on the right of current element
            last = mid;
            low = mid + 1;
            continue;   //# If we don't continue, value of low will change in else condition
        }

        if (target < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return last;
}

int findLastR(int *arr, int target, int low, int high)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (target == arr[mid])
    {
        int right = findLastR(arr, target, mid + 1, high);
        return (right == -1) ? mid : right;
    }

    if (target < arr[mid])
        return findLastR(arr, target, low, mid - 1);
    else
        return findLastR(arr, target, mid + 1, high);
}

int main()
{
    int arr[] = {1, 2, 2, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int target = 2;

    int first, last;

    first = findFirstI(arr, target, 0, size - 1);
    last = findLastI(arr, target, 0, size - 1);
    cout << "Iterative Total Count: " << last - first + 1 << endl;

    first = findFirstR(arr, target, 0, size - 1);
    last = findLastR(arr, target, 0, size - 1);
    cout << "Recursive Total Count: " << last - first + 1 << endl;
}