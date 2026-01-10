/*
$ LeetCode: 643. Maximum Average Subarray I

You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value.
Any answer with a calculation error less than 10-5 will be accepted.

$ Example 1:
# Input: nums = [1,12,-5,-6,50,3], k = 4
# Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

$ Example 2:
# Input: nums = [5], k = 1
# Output: 5.00000
*/

#include <bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int> &nums, int k)
{
    int n = nums.size();

    int windowSum = 0;

    for (int i = 0; i < k; i++)
        windowSum += nums[i];

    double average = static_cast<double>(windowSum) / k;
    double maxAverage = average;

    for (int right = k; right < n; right++)
    {
        windowSum += nums[right];
        windowSum -= nums[right - k];

        average = static_cast<double>(windowSum) / k;
        maxAverage = max(average, maxAverage);
    }
    
    return maxAverage;
}
//! Instead of calculating average everytime
//! How about we find window with maxSum and then return the (maxSum / k)

double findMaxAverage(vector<int> &nums, int k)
{
    int n = nums.size();

    int windowSum = 0;

    for (int i = 0; i < k; i++)
        windowSum += nums[i];

    int maxSum = windowSum;

    for (int right = k; right < n; right++)
    {
        windowSum += nums[right];
        windowSum -= nums[right - k];

        maxSum = max(windowSum, maxSum);
    }

    return static_cast<double>(maxSum) / k;
}

int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    double result = findMaxAverage(nums, k);

    cout << result;
}