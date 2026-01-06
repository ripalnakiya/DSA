/*
$ LeetCode: 1. Two Sum

Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

$ Example 1:
# Input: nums = [2,7,11,15], target = 9
# Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

$ Example 2:
# Input: nums = [3,2,4], target = 6
# Output: [1,2]

$ Example 3:
# Input: nums = [3,3], target = 6
# Output: [0,1]
*/

/*
! Approach 1: Brute Force
    For each nums[i], search for (target - nums[i]) in the rest of the elements
    ~ Time Complexity: O(n^2)
    ~ Space Complexity: O(1)

! Approach 2: Hashing
    Store visited elements and check for the complement
    ~ Time Complexity: O(n) average, O(n²) worst case
    ~ Space Complexity: O(n)

! Approach 3: Sorting + Two Pointers    (More appropriate for "Two Sum II")
    Sort the array and use left/right pointers
    ~ Time Complexity: O(n log n)
    ~ Space Complexity: O(log n) due to sorting
    @ NOTE: If original indices are required, extra O(n) space is needed - To store (value, index) pairs
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> indexOf;

    for (int i = 0; i < nums.size(); i++)
    {
        int need = target - nums[i];
        if (indexOf.count(need)) // We can also use .contains() for C++20
            return {indexOf[need], i};
        indexOf[nums[i]] = i;
    }
    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);

    for (auto &i : result)
        cout << i << " ";
}