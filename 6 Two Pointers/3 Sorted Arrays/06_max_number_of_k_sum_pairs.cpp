/*
$ LeetCode: 1679. Max Number of K-Sum Pairs

You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

$ Example 1:
# Input: nums = [1,2,3,4], k = 5
# Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.

$ Example 2:
# Input: nums = [3,1,3,4,3], k = 6
# Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
*/

/*
! Core Idea:
We already have used the approach to solve this problem in "Two Sum II" and "Boats to save people"
*/

#include <bits/stdc++.h>
using namespace std;

int maxOperations(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());

    int count = 0;
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        int sum = nums[left] + nums[right];

        if (sum == k)
        {
            count++;
            left++;
            right--;
        }
        else if (sum > k)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return count;
}

int main()
{
    vector<int> nums = {3, 1, 3, 4, 3};
    int k = 6;
    int result = maxOperations(nums, k);
    cout << result;
}