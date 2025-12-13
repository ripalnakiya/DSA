#include <bits/stdc++.h>
using namespace std;

int findSum(int *arr, int size)
{
    if (size == 1)
        return arr[0];
    return arr[size-1] + findSum(arr, size-1);
}

//$ If recursive call is the last statement(Tail Recursion)
//$ the compiler does not need to save the state of parent call
//! Tail recursive function
int arrSum(int* array, int size, int sum = 0)
{
    if (size == 0) 
        return sum;
    return arrSum(array, size - 1, sum + array[size - 1]);
}
//# This is a tail-recursive approach, which compilers might optimize, 
//~ but C++ doesn't guarantee tail-call elimination.
//~ So you don’t actually get a performance win here.

int main()
{
    int arr[5] = {2, 4, 6, 8, 10};
    cout << findSum(arr, sizeof(arr)/sizeof(arr[0]));
    cout << arrSum(arr, sizeof(arr)/sizeof(arr[0]));
}