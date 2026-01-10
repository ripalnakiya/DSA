/*
$ LeetCode: 485. Max Consecutive Ones

Given a binary array nums, return the maximum number of consecutive 1's in the array.

$ Example 1:
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
The maximum number of consecutive 1s is 3.

$ Example 2:
Input: nums = [1,0,1,1,0,1]
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        if (nums[right] == 0)
            left = right + 1;
            
        maxLength = max(right - left + 1, maxLength);
    }
    return maxLength;
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    int result = findMaxConsecutiveOnes(nums);

    cout << result;
}