#include <bits/stdc++.h>
using namespace std;

bool isSorted(int *arr, int index, int size)
{
    if (index == size - 1)
        return true;
    
    // if (arr[index] < arr[index + 1])
    //     return isSorted(arr, index + 1, size);

    // return false;
    //! This method would only check for Strictly Increasing, {5, 5} would give false

    if (arr[index] > arr[index + 1])    //$ allows equality
        return false;

    return isSorted(arr, index + 1, size);
    //! This method would also allow for equality, {5, 5} will not give false
}

//$ There is a differece b/w Strictly Increasing and Increasing
//# Strictly Increasing = {2, 4, 6, 8}
//# Icreasing = {2, 4, 6, 6, 8}

// int trend = 0;
//@ Using of global variables in recursion makes the function not pure.
//@ Makes recursion unsafe and confusing.
//@ Hence, here, we've used trend as default parameter.

bool isSorted2(int *arr, int index, int size, int trend = 0)
{
    if (index == (size -1))
        return true;

    int a = arr[index];
    int b = arr[index + 1];

    //$ Case 1: equal values → no change in trend
    if (a == b)
        return isSorted2(arr, index + 1, size, trend);
    
    //$ Case 2: increasing pair
    if (a < b)
    {
        // If trend was descending earlier → invalid
        if (trend == -1)
            return false;

        // Otherwise trend becomes ascending (1)
        return isSorted2(arr, index + 1, size, 1);
    }

    //$ Case 3: decreasing pair (a > b)
    {
        // If trend was ascending earlier → invalid
        if (trend == 1)
            return false;

        // Otherwise trend becomes descending (-1)
        return isSorted2(arr, index + 1, size, -1);
    }
}

int main()
{
    int arr[] = {8, 5, 3, 2, 2, 1};
    cout << isSorted(arr, 0, 5) << endl;
    cout << isSorted2(arr, 0, 5);
}