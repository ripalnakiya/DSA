#include <bits/stdc++.h>
using namespace std;

//$ There is a differece b/w Strictly Increasing and Increasing
//# Strictly Increasing = {2, 4, 6, 8}
//# Icreasing = {2, 4, 6, 6, 8}

bool isSortedStrictly(int *arr, int index, int size)
{
    if (index == size - 1)
        return true;
    
    if (arr[index] < arr[index + 1])
        return isSortedStrictly(arr, index + 1, size);

    return false;
    //! This method would only check for Strictly Increasing, {5, 5} would give false
}

bool isSorted(int *arr, int index, int size)
{
    if (index == size - 1)
        return true;

    if (arr[index] > arr[index + 1])    //$ allows equality
        return false;

    return isSorted(arr, index + 1, size);
    //! This method would also allow for equality, {5, 5} will not give false
}

int main()
{
    int arr[] = {1, 2, 2, 3, 8, 10};
    cout << isSortedStrictly(arr, 0, 5) << "\n";
    cout << isSorted(arr, 0, 5);
}