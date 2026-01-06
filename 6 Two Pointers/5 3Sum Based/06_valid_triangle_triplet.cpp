/*
$ LeetCode: 611. Valid Triangle Number

Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

$ Example 1:
# Input: nums = [2,2,3,4]
# Output: 3
Explanation: Valid combinations are:
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

$ Example 2:
# Input: nums = [4,2,3,4]
# Output: 4
*/

#include <bits/stdc++.h>
using namespace std;

/*
    For a sorted array, you only need ONE inequality to check a valid triangle:
    If nums[1] + nums[2] > nums[3], then the other two conditions are automatically satisfied.

    nums[2] + nums[3]    will always be      > nums[1]
    nums[3] + nums[1]    will always be      > nums[2]
*/

int triangleNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int count = 0;

    for (int k = nums.size() - 1; k > 1; k--)
    {
        int longest = nums[k];
        int left = 0;
        int right = k - 1;

        while (left < right)
        {
            if (nums[left] + nums[right] > longest)
            {
                // All pairs (left ... right-1, right) form valid triangles
                count += right - left;
                right--;
            }
            else
            {
                left++;
            }
        }
    }

    return count;
}

int main()
{
    vector<int> nums = {2, 2, 3, 4};

    int result = triangleNumber(nums);
    cout << result;
}