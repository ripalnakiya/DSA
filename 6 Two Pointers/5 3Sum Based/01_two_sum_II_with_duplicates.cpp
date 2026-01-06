/*
Same as "Two Sum II - Input Array Is Sorted", But it contains duplicate elements, and has more than one answer
So, return all possible unique solutions.

# Input: numbers = [1, 1, 1, 2, 2, 3, 3, 3], target = 4
# Output: [[1, 3], [2, 2]]
*/

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> twoSum(vector<int> &nums, int target)
{
    vector<pair<int, int>> result;

    int left = 0, right = nums.size() - 1;

    while (left < right)
    {
        int sum = nums[left] + nums[right];

        if (sum == target)
        {
            result.push_back({nums[left], nums[right]});

            // Move both pointers and also skip the repeating elements

            left++;
            right--;

            while (nums[left] == nums[left - 1] && left < right)
                left++;

            while (nums[right] == nums[right + 1] && left < right)
                right--;
        }
        else if (sum < target)
            left++;
        else // sum > target
            right--;
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3, 3, 3};
    int target = 4;
    vector<pair<int, int>> result = twoSum(nums, target);

    for (auto &i : result)
        cout << i.first << " " << i.second << endl;
}