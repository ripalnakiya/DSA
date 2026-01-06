/*
$ LeetCode: 2367. Number of Arithmetic Triplets

You are given a 0-indexed,
strictly increasing integer array nums and a positive integer diff.

A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:
    i < j < k,
    nums[j] - nums[i] == diff, and
    nums[k] - nums[j] == diff.

Return the number of unique arithmetic triplets.

$ Example 1:
# Input: nums = [0,1,4,6,7,10], diff = 3
# Output: 2
Explanation:
(1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 and 4 - 1 == 3.
(2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 and 7 - 4 == 3.

$ Example 2:
# Input: nums = [4,5,6,7,8,9], diff = 2
# Output: 2
Explanation:
(0, 2, 4) is an arithmetic triplet because both 8 - 6 == 2 and 6 - 4 == 2.
(1, 3, 5) is an arithmetic triplet because both 9 - 7 == 2 and 7 - 5 == 2.
*/

#include <bits/stdc++.h>
using namespace std;

//@ Hash Table approach
int arithmeticTriplets(vector<int> &nums, int diff)
{
    unordered_set<int> seen(nums.begin(), nums.end());

    int count = 0;

    // Since array is strictly increasing, we'll always get i < j < k
    for (int num : nums)
        if (seen.count(num + diff) && seen.count(num + 2 * diff))
            count++;

    return count;
}
//~ Time: O(n), Space: O(n)

//@ Three Pointer approach
/*
    The reason we're able to use three pointers here, bcz all triplets will be purely unique... 
    How ?
    In triplet (1, 3, 5) we can never replace any number... (1, 3, 7) ? Wrong answer.
    So at the correction combination, we move all three pointers by 1 index.
*/
int arithmeticTriplets(vector<int> &nums, int diff)
{
    int n = nums.size();
    int count = 0;
    int i = 0, j = 1, k = 2;

    while (i < n - 2 && j < n - 1 && k < n)
    {
        int d1 = nums[j] - nums[i];
        int d2 = nums[k] - nums[j];

        if (d1 == diff && d2 == diff)
        {
            count++;
            i++;
            j++;
            k++;
        }
        else if (d1 < diff)
        {
            j++;
        }
        else if (d1 > diff)
        {
            i++;
        }
        else if (d2 < diff)
        {
            k++;
        }
        else if (d2 > diff)
        {
            j++;
        }
    }
    return count;
}
//~ Time: O(n), Space: O(1)

int main()
{
    vector<int> nums = {4, 5, 6, 7, 8, 9};
    int diff = 2;

    int result = arithmeticTriplets(nums, diff);
    cout << result;
}