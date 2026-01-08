/*
$ Wiggle Sort

Given an integer array nums,
reorder it in-place such that it satisfies the following wiggle property:

nums[0] <= nums[1] >= nums[2] <= nums[3] >= nums[4] ...

$ Example 1
# Input: nums = [3,5,2,1,6,4]
# Output: [1, 6, 2, 5, 3, 4]
# Output: [3, 5, 1, 6, 2, 4]
*/

/*
!   Approach 1: Two pointers
    Sort the nums,
    Place the largest available element at arr[1], arr[3], arr[5]...
    Place the smallest available element at arr[0], arr[2], arr[4]...
    ~ Time: O(n log n), Space: O(n)

!    Approach 2: Greedy (Invariant based)
    Swap adjacent elements if they don’t satisfy the wiggle condition
    ~ Time: O(n), Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

/*
!   Invariant we've used:
        0...i-1         => sorted
        i...n           => chaos
*/
vector<int> wiggleSort(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        if (
            (i & 1 && nums[i] < nums[i - 1]) // If odd index AND it's smaller than previous element, swap
            ||
            (!(i & 1) && nums[i] > nums[i - 1]) // If even index AND it's larger than previous element, swap
        )
        {
            swap(nums[i], nums[i - 1]);
        }
    }
    return nums;
}

int main()
{
    vector<int> nums = {3, 5, 2, 1, 6, 4};

    vector<int> result = wiggleSort(nums);

    for (auto i : result)
        cout << i << " ";
}