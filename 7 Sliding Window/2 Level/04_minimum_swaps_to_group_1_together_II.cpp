/*
$ LeetCode: 2134. Minimum Swaps to Group All 1's Together II

A swap is defined as taking two distinct positions in an array and swapping the values in them.

A circular array is defined as an array 
where we consider the first element and the last element to be adjacent.

Given a binary circular array nums, 
return the minimum number of swaps required to group all 1's present in the array together at any location.

$ Example 1:
# Input: nums = [0,1,0,1,1,0,0]
# Output: 1
Explanation: Here are a few of the ways to group all the 1's together:
[0,0,1,1,1,0,0] using 1 swap.
[0,1,1,1,0,0,0] using 1 swap.
[1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
There is no way to group all 1's together with 0 swaps.
Thus, the minimum number of swaps required is 1.

$ Example 2:
# Input: nums = [0,1,1,1,0,0,1,1,0]
# Output: 2
Explanation: Here are a few of the ways to group all the 1's together:
[1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
[1,1,1,1,1,0,0,0,0] using 2 swaps.
There is no way to group all 1's together with 0 or 1 swaps.
Thus, the minimum number of swaps required is 2.

$ Example 3:
# Input: nums = [1,1,0,0,1]
# Output: 0
Explanation: All the 1's are already grouped together due to the circular property of the array.
Thus, the minimum number of swaps required is 0.
*/

#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &nums)
{
    int n = nums.size();

    // Count total number of 1's to decide out window size
    int totalCount = 0;
    for (int i = 0; i < n; i++)
        if (nums[i] == 1)
            totalCount++;

    // Calculate first window
    int windowCount = 0;
    for (int i = 0; i < totalCount; i++)
        if (nums[i] == 1)
            windowCount++;

    int maxWindowCount = windowCount;

    // Slide window over circular array
    for (int right = totalCount; right < n + totalCount; right++)
    {
        if (nums[right % n] == 1)
            windowCount++;
        if (nums[(right - totalCount) % n] == 1)
            windowCount--;

        maxWindowCount = max(maxWindowCount, windowCount);
    }

    return totalCount - maxWindowCount;
}

int main()
{
    vector<int> a = {0, 1, 1, 1, 0, 0, 1, 1, 0};
    cout << minSwaps(a);
}