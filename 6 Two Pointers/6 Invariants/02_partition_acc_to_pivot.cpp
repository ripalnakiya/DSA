/*
$ LeetCode: 2161. Partition Array According to Given Pivot

You are given a 0-indexed integer array nums and an integer pivot.
Rearrange nums such that the following conditions are satisfied:

Every element less than pivot appears before every element greater than pivot.
Every element equal to pivot appears in between the elements less than and greater than pivot.
The relative order of the elements less than pivot and the elements greater than pivot is maintained.

More formally,
consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element.
If i < j and both elements are smaller (or larger) than pivot, then pi < pj.

Return nums after the rearrangement.

$ Example 1:
# Input: nums = [9,12,5,10,14,3,10], pivot = 10
# Output: [9,5,3,10,10,12,14]
Explanation:
The elements 9, 5, and 3 are less than the pivot so they are on the left side of the array.
The elements 12 and 14 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [9, 5, 3] and [12, 14] are the respective orderings.

$ Example 2:
# Input: nums = [-3,4,3,2], pivot = 2
# Output: [-3,2,4,3]
Explanation:
The element -3 is less than the pivot so it is on the left side of the array.
The elements 4 and 3 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [-3] and [4, 3] are the respective orderings.
*/

/*
!   After trying and failing by using approaches like:
        Dutch National Flag
        Lomuto-style Partition
        Hoarte-styel Partition
    ~ We failed becuase these approaches rely on swapping
    ~ (Swapping destroys relative order and violates stability)

!   Approach for problems involving Stable partition
    ~ We'll have to use extra space to have stable partition
*/

/*
!   This question involves stable partitioning, not in-place partitioning.
    We can use three queues and one pass: Time O(n), Space O(n)

    @ NOTE: Partitioning + order preserved
    "In-place partition breaks relative order. I’ll use extra space for stability."
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> pivotArray(vector<int> &nums, int pivot)
{
    vector<int> smaller, equal, larger;

    for (int number : nums)
    {
        if (number < pivot)
            smaller.push_back(number);
        else if (number == pivot)
            equal.push_back(number);
        else
            larger.push_back(number);
    }

    vector<int> result;
    result.reserve(nums.size());

    result.insert(result.end(), smaller.begin(), smaller.end());
    result.insert(result.end(), equal.begin(), equal.end());
    result.insert(result.end(), larger.begin(), larger.end());

    return result;
}

int main()
{
    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;

    vector<int> result = pivotArray(nums, pivot);

    for (auto &i : result)
        cout << i << " ";
}