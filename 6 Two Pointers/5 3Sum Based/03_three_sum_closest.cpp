/*
$ LeetCode: 16. 3Sum Closest

Given an integer array nums of length n and an integer target,
find three integers at distinct indices in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

$ Example 1:
# Input: nums = [-1,2,1,-4], target = 1
# Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

$ Example 2:
# Input: nums = [0,0,0], target = 1
# Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
*/

#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());

    int closest = INT_MAX;
    int closestSum = 0;

    for (int i = 0; i < nums.size() - 2; i++)
    {

        // Avoid duplicate triplet formation
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            int diff = abs(target - sum);
            if (diff < closest)
            {
                closest = diff;
                closestSum = sum;
            }

            if (sum == target)  // closest is 0, there can nothing be closer than 0
                return closestSum;

            if (sum < target)
                left++;
            else    // sum > target
                right--;
        }
    }
    return closestSum;
}

int main()
{
    vector<int> nums = {0, 0, 0};
    int target = 1;

    int result = threeSumClosest(nums, target);
    cout << result;
}