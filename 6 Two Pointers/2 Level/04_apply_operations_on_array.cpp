/*
$ LeetCode: 2460. Apply Operations to an Array

You are given a 0-indexed array nums of size n consisting of non-negative integers.

You need to apply n - 1 operations to this array where, in the ith operation (0-indexed), 
you will apply the following on the ith element of nums:

If nums[i] == nums[i + 1], then multiply nums[i] by 2 and set nums[i + 1] to 0. 
Otherwise, you skip this operation.
After performing all the operations, shift all the 0's to the end of the array.

For example, the array [1,0,2,0,0,1] after shifting all its 0's to the end, is [1,2,1,0,0,0].
Return the resulting array.

Note that the operations are applied sequentially, not all at once.

$ Example 1:
# Input: nums = [1,2,2,1,1,0]
# Output: [1,4,2,0,0,0]

$ Example 2:
# Input: nums = [0,1]
# Output: [1,0]
Explanation: No operation can be applied, we just shift the 0 to the end.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> applyOperations(vector<int> &nums)
{

    // Perform the operations
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }

    // Move zeroes to end
    int k = 0;
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] != 0)
            swap(nums[k++], nums[i]);

    return nums;
}
//~ It's not possible to combine both operations in one loop.

int main()
{
    vector<int> nums = {0, 1};
    vector<int> result = applyOperations(nums);

    for (auto &i : result)
        cout << i << " ";
}