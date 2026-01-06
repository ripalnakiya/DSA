/*
$ LeetCode: 15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

$ Example 1:
# Input: nums = [-1,0,1,2,-1,-4]
# Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

$ Example 2:
# Input: nums = [0,1,1]
# Output: []
Explanation: The only possible triplet does not sum up to 0.

$ Example 3:
# Input: nums = [0,0,0]
# Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;

    /*  NOTE: When nums = {0} and target = 0
     *
     *  nums.size() is unsigned and cannot represent negative numbers
     *      nums.size() - k
     *      = (size_t)1 - (int)2
     *      = very_large_number   // underflow
     *
     *  So, Never subtract from size() unless you’ve already verified the size is large enough.
     */

    /*  ALTERNATIVE:
     *
     *  int n = nums.size();
     *  i <= n - k
     *
     *  This works because n - k is now a (forced) signed calculation
     */

    int n = nums.size();

    // For each nums[i], perform two sum
    for (int i = 0; i < n - 2; i++)
    { // i < (n - 2), so that last two slots remain for left and right pointer

        // Make sure we don't choose duplicate nums[i] value
        // i.e. trying not to form a triplet using same previous nums[i]
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int target = -nums[i];

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = nums[left] + nums[right];

            if (sum == target)
            {
                result.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1])
                    left++;

                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
            else if (sum < target)
            {
                left++;
            }
            else // sum > target
            {
                right--;
            }
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);

    for (auto &i : result)
    {
        for (auto &j : i)
            cout << j << " ";
        cout << endl;
    }
}