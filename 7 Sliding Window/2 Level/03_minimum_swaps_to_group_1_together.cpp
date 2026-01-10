/*
$ GeeksForGeeks: Minimum Swaps required to group all 1's together

Given an array of 0's and 1's, we need to write a program to find the minimum number of swaps required to group all 1's present in the array together.

$ Examples:
# Input: arr[] = [1, 0, 1, 0, 1]
# Output: 1
Explanation: Only 1 swap is required to group all 1's together.
Swapping index 1 with 4 will  give arr[] = [1, 1, 1, 0, 0]

# Input: arr[] = [1, 1, 0, 1, 0, 1, 1]
# Output: 2
Explanation: Only 2 swap is required to group all 1's together. Swapping index 0 with 2 and
1 with 4 will  give arr[] = [0, 0, 1, 1, 1, 1, 1]

# Input: arr[] = [0, 0, 0]
# Output: -1
Explanation: No 1s are present in the array, so return -1.
*/

#include <bits/stdc++.h>
using namespace std;

/*
@   Approach 1: Using Nested loops - O(n^2) Time and O(n) Space
    First count total number of 1’s  in the array.
    Suppose this count is x,
    now we need to find the subarray of length x with maximum number of 1’s.
    And minimum swaps required will be the number of 0’s in this subarray of length x.
*/

/*
@   Approach 2: Maintaining Window K(count of 1) - O(n) Time and O(1) Space
    Count the total number of 1s (x) in the array,
    then find a subarray of length x with the maximum 1s using a sliding count.
    Track the maximum 1s in any such subarray and return x - maxOnes as the minimum swaps needed.
*/

int minSwaps(vector<int> &arr)
{

    // Total count of 1's in the array
    int totalCount = 0;
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == 1)
            totalCount++;

    /* Find a window that already has the maximum number of 1s, and swap the rest in.
     * Bcz:
     * Total number of 1s is fixed.
     * Final grouped block must have length = total number of 1s.
     * Every 0 inside that block must be swapped with a 1 outside.
     */

    // First window of size k
    int windowCount = 0;
    for (int i = 0; i < totalCount; i++)
        if (arr[i] == 1)
            windowCount++;

    int maxWindowCount = windowCount;

    // Find best sub-array of size k, with maximum number of 1's
    for (int i = totalCount; i < arr.size(); i++)
    {
        if (arr[i] == 1)
            windowCount++;
        if (arr[i - totalCount] == 1)
            windowCount--;

        maxWindowCount = max(windowCount, maxWindowCount);
    }

    // The number of zeroes in our best sub-array is the minimum swap count
    return totalCount - maxWindowCount;
}

int main()
{
    vector<int> a = {0, 0, 1, 0, 1, 1, 0, 0, 1};
    cout << minSwaps(a);
}