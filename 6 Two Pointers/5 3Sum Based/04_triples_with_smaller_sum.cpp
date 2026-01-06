/*
$ GeeksForGeeks: Triplets with Smaller Sum

Given an array arr[] of distinct integers of size n and a value sum,
the task is to find the count of triplets (i, j, k),
having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.

$ Example 1:
# Input: arr[] = {-2, 0, 1, 3}, sum = 2
# Output:  2
Explanation: Below are triplets with sum less than 2 (-2, 0, 1) and (-2, 0, 3).

$ Example 2:
# Input: arr[] = {5, 1, 3, 4, 7}, sum = 12
# Output: 4
Explanation: Below are triplets with sum less than 12 (1, 3, 4), (1, 3, 5), (1, 3, 7) and (1, 4, 5).

Expected Time Complexity: O(n^2).
Expected Auxiliary Space: O(1).
*/

/*
! Core Idea:
    Try to take the advantage of sorted array
    (Greedy)

    Ex: {1, 3, 4, 5, 7}, sum = 12
    If {1,3,7} is less than 12, than all elements on the left of 7 will form valid triplets
*/

#include <bits/stdc++.h>
using namespace std;

int smallerTripletSum(vector<int> &nums, int sum)
{
    sort(nums.begin(), nums.end());

    int count = 0;

    for (int i = 0; i < nums.size() - 2; i++)
    {

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right)
        {
            int currentSum = nums[i] + nums[left] + nums[right];

            if (currentSum < sum)
            {
                count = count + right - left; // All triplets (i, left, left+1 ... right) are valid, since array is sorted
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return count;
}

int main()
{
    vector<int> nums = {5, 1, 3, 4, 7};
    int sum = 12;

    int result = smallerTripletSum(nums, sum);
    cout << result;
}