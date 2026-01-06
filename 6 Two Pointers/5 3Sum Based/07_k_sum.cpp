/*
$ LeetCode: 18. 4Sum

Given an array nums of n integers,
return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
    0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

$ Example 1:
# Input: nums = [1,0,-1,0,-2,2], target = 0
# Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

$ Example 2:
# Input: nums = [2,2,2,2,2], target = 8
# Output: [[2,2,2,2]]
*/

/*
We can implement 4Sum by wrapping 3Sum in another loop.
But wait - there is a catch.
If an interviewer asks you to solve 4Sum, they can follow-up with 5Sum, 6Sum, and so on.
What they are really expecting at this point is a kSum solution.
Therefore, we will focus on a generalized implementation here.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> twoSum(vector<int> &nums, int start, long long target)
{
    vector<vector<int>> result;

    int n = nums.size();

    int left = start;
    int right = n - 1;

    while (left < right)
    {
        long long sum = (long long)nums[left] + nums[right];
        if (sum == target)
        {
            result.push_back({nums[right], nums[left]});
            left++;
            right--;
            while (left < right && nums[left] == nums[left - 1])
                left++;
            while (left < right && nums[right] == nums[right + 1])
                right--;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return result;
}

vector<vector<int>> kSum(vector<int> &nums, int start, long long target, int k)
{
    vector<vector<int>> result;

    if (start >= nums.size())
        return result;
    // Added this condition to perform below pruning, without going out of bounds

    /*  We need k numbers that add up to target...
     *  The minimum possible sum we can make is:    minSum = k * nums[start]
     *  The maximum possible sum you can make is:   maxSum = k * nums.back()
     *
     *  If target is outside this range, then:
     *  No combination is possible
     *
     *  So, if (minSum > target || maxSum < target) return;
     */
    int average_value = target / k;
    if (nums[start] > average_value || nums.back() < average_value)
        return result;

    // Base Case
    if (k == 2)
        return twoSum(nums, start, target);

    int n = nums.size();
    for (int i = start; i <= n - k; i++)
    {
        if (i > start && nums[i] == nums[i - 1])
            continue;

        // Take every (k−1)-sum subset and attach nums[i] to it to form a k-sum subset.
        for (auto subset : kSum(nums, i + 1, target - nums[i], k - 1))
        {
            subset.push_back(nums[i]);
            result.push_back(subset);
        }
    }

    return result;
}

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    return kSum(nums, 0, target, 4);
}

int main()
{
    vector<int> nums = {0, 0, 0, 0};
    int target = 0;

    vector<vector<int>> result = fourSum(nums, target);

    for (auto &i : result)
    {
        for (auto &j : i)
            cout << j << " ";
        cout << endl;
    }
}