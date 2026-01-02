/*
$ LeetCode: 78

Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

$ Example 1:
# Input: nums = [1,2,3]
# Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

$ Example 2:
# Input: nums = [0]
# Output: [[],[0]]
*/

#include <bits/stdc++.h>
using namespace std;

//@ Approach 1: Take / Not Take
void findSubsets(int index, vector<int> &store, vector<vector<int>> &result, vector<int> &nums)
{
    if (index >= nums.size())
    {
        result.push_back(store);
        return;
    }

    store.push_back(nums[index]);
    findSubsets(index + 1, store, result, nums);
    store.pop_back();
    findSubsets(index + 1, store, result, nums);
}

//@ Approach 2: Loop Branching
void findSubsets(int index, vector<int> &store, vector<vector<int>> &result, vector<int> &nums)
{
    result.push_back(store);

    for (int i = index; i < nums.size(); i++)
    {
        store.push_back(nums[i]);
        findSubsets(i + 1, store, result, nums);
        store.pop_back();
    }
}
//~ It makes less number of fuction calls (We get the result mid way, instead of on leaf nodes

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> store;
    vector<vector<int>> result;
    findSubsets(0, store, result, nums);
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    for (vector<int> v : result)
    {
        for (int n : v)
            cout << n << " ";
        cout << endl;
    }
}