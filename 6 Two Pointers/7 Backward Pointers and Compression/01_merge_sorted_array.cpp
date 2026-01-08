/*
$ LeetCode: 88. Merge Sorted Arrays

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1.

To accommodate this, nums1 has a length of m + n,
where the first m elements denote the elements that should be merged,
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

$ Example 1:
# Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
# Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

$ Example 2:
# Input: nums1 = [1], m = 1, nums2 = [], n = 0
# Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

$ Example 3:
# Input: nums1 = [0], m = 0, nums2 = [1], n = 1
# Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
*/

#include <bits/stdc++.h>
using namespace std;

/*  This question is almost similar to the technique we use in the merge sort,
 *  Except, that we can't use extra array here (I mean we can sort without creating extra array)
 *
 *  How ?
 *
 *  Since last few elements are empty for nums2,
 *  And we cannot modify the nums1 from starting indices.
 *
 *  Let's start merging from the end of the nums1,
 *  You can imagine here 3 arrays (One starts from the last index of nums1)
 *
 *  We'll merge the arrays in reverse order.
 */

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int first = m - 1, second = n - 1, third = m + n - 1;

    while (first >= 0 && second >= 0)
    {
        if (nums1[first] > nums2[second])
            nums1[third--] = nums1[first--];
        else
            nums1[third--] = nums2[second--];
    }

    // If second pointer reaches 0, means all elements of nums2 has been copied at correct position
    // The elements of nums1 already exist in the original array in sorted order, so we don't need to do anything

    // If first pointer reaches 0, means all elements of nums1 has been copied at correct position
    // But nums2 may have some remaining elements
    while (second >= 0)
        nums1[third--] = nums2[second--];
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    merge(nums1, m, nums2, n);

    for (auto &i : nums1)
    {
        cout << i << " ";
    }
}