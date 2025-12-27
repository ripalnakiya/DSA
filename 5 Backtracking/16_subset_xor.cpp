/*
$ LeetCode: 1863. Sum of All Subset XOR Totals

The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
Given an array nums, return the sum of all XOR totals for every subset of nums.

Note: Subsets with the same elements should be counted multiple times.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

# Input: nums = [1,3]
# Output: 6
Explanation: The 4 subsets of [1,3] are:
- The empty subset has an XOR total of 0.
- [1] has an XOR total of 1.
- [3] has an XOR total of 3.
- [1,3] has an XOR total of 1 XOR 3 = 2.
0 + 1 + 3 + 2 = 6
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int index, int currentXor, int &result, vector<int> &nums)
{
    if (index == nums.size())
    {
        result += currentXor;
        return;
    }

    solve(index + 1, currentXor xor nums[index], result, nums);

    solve(index + 1, currentXor, result, nums);
}

int subsetXORSum(vector<int> &nums)
{
    int result = 0;
    int currentXor = 0;
    solve(0, currentXor, result, nums);
    return result;
}

int main()
{
    vector<int> nums = {1, 2};
    int result = subsetXORSum(nums);
    cout << result << endl;
}