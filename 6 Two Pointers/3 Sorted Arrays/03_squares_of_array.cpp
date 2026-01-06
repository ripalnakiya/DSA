/*
$ LeetCode: 977. Squares of a Sorted Array

Given an integer array nums sorted in non-decreasing order,
return an array of the squares of each number sorted in non-decreasing order.

$ Example 1:
# Input: nums = [-4,-1,0,3,10]
# Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

$ Example 2:
# Input: nums = [-7,-3,2,3,11]
# Output: [4,9,9,49,121]
*/

/*
! Core Idea:
! After squaring each element, we find that there exits two sorted arrays in the numbs
~ [16, 1, 0, 9, 100]
~ Array 1: From index 0 to 1
~ Array 2: From index 2 to n

Let's have two pointers at both ends of array,
And use merge sort technique of merging two sorted arrays, into one array.

Since we'll be mergeing two decreasing arrays,
we'll start including the elements in new array from last it's index (That way last index will have larger element)
And resultant array will be properly sorted.

We can take reference from "Two Pointers / Basic / Merge Sorted Arrays" solution
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n);

    int left = 0, right = n - 1;
    int k = n - 1;

    // left == right, to handle single element cases
    while (left <= right)
    {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];
        if (leftSquare > rightSquare)
        {
            result[k--] = leftSquare;
            left++;
        }
        else
        {
            result[k--] = rightSquare;
            right--;
        }
    }

    // There are NO left over elements as left and right pointer covers all of them

    return result;
}

int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = sortedSquares(nums);

    for (auto &i : result)
        cout << i << " ";
}