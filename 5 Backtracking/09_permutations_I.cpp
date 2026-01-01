/*
$ LeetCode: 46
Given an array nums of distinct integers, return all the possible permutations.
You can return the answer in any order.
All the integers of nums are unique.

$ Example 1:
# Input: nums = [1,2,3]
# Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

$ Example 2:
# Input: nums = [0,1]
# Output: [[0,1],[1,0]]

$ Example 3:
# Input: nums = [1]
# Output: [[1]]
*/

#include <bits/stdc++.h>
using namespace std;

void makePermutations(vector<bool> &used, vector<int> &store, vector<vector<int>> &result, vector<int> &nums)
{
    if (store.size() == nums.size())
    {
        result.push_back(store);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (used[i])
            continue;

        store.push_back(nums[i]);
        used[i] = true;
        // `used` vector is there to reduce the input size, we don't need index+1 etc.
        makePermutations(used, store, result, nums);
        used[i] = false;
        store.pop_back();
    }
}
//~ This approach uses extra vector, which add to the space complexity of program.

vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> store;
    vector<vector<int>> result;
    vector<bool> used(nums.size(), false);
    makePermutations(used, store, result, nums);
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums);

    for (vector<int> v : result)
    {
        for (int n : v)
            cout << n << " ";
        cout << endl;
    }
}