/*
$ LeetCode: 219. Contains Duplicate II

Given an integer array nums and an integer k,
return true if there are two distinct indices i and j in the array
such that nums[i] == nums[j] and abs(i - j) <= k.

$ Example 1:
# Input: nums = [1,2,3,1], k = 3
# Output: true

$ Example 2:
# Input: nums = [1,0,1,1], k = 1
# Output: true

$ Example 3:
# Input: nums = [1,2,3,1,2,3], k = 2
# Output: false
*/

#include <bits/stdc++.h>
using namespace std;

//@ Approach 1: Classic Fixed Window
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_set<int> seen;

    for (int i = 0; i <= k; i++)
    {
        if (!seen.count(nums[i]))
            seen.insert(nums[i]);
        else
            return true;
    }

    for (int right = k + 1; right < nums.size(); right++)
    {
        seen.erase(nums[right - k - 1]);

        if (!seen.count(nums[right]))
            seen.insert(nums[right]);
        else
            return true;
    }

    return false;
}

//@ Approach 2: Better
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_set<int> seen;

    for (int i = 0; i < nums.size(); i++)
    {
        if (seen.count(nums[i]))
            return true;

        seen.insert(nums[i]);

        if (seen.size() > k)
            seen.erase(nums[i - k]);
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1, 2, 3};
    int k = 2;

    bool result = containsNearbyDuplicate(nums, k);

    cout << result;
}