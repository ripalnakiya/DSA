/*
$ GeeksForGeeks: Max Sum Subarray of size K

Given an array of integers arr[]  and a number k.
Return the maximum sum of a subarray of size k.

Note: A subarray is a contiguous part of any given array.

$ Example 1:
# Input: arr[] = [100, 200, 300, 400], k = 2
# Output: 700
Explanation: arr2 + arr3 = 700, which is maximum.

$ Example 2:
# Input: arr[] = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4
# Output: 39
Explanation: arr1 + arr2 + arr3 + arr4 = 39, which is maximum.

$ Example 3:
# Input: arr[] = [100, 200, 300, 400], k = 1
# Output: 400
Explanation: arr3 = 400, which is maximum.
*/

#include <bits/stdc++.h>
using namespace std;

int maxSumSubarrayOfSizeK(vector<int> &arr, int k)
{
    int n = arr.size();

    // Edge case: window size larger than array
    if (k > n)  return -1;

    int windowSum = 0;

    // Calculate sum of first window
    for (int i = 0; i < k; i++)
        windowSum += arr[i];

    int maxSum = windowSum;

    // Slide the window
    for (int right = k; right < n; right++)
    {
        windowSum += arr[right];     // add new element
        windowSum -= arr[right - k]; // remove old element

        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main()
{
    vector<int> arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k = 4;

    int result = maxSumSubarrayOfSizeK(arr, k);

    cout << result;
}