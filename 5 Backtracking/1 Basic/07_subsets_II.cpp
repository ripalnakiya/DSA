/*
$ LeetCode: 90
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

$ Example 1:
# Input: nums = [1,2,2]
# Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

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

    //~ Not take the same element(s)
    int nextIndex = index + 1;
    while (nextIndex < nums.size() && nums[index] == nums[nextIndex])
        nextIndex++;

    findSubsets(nextIndex, store, result, nums);
}

//@ Approach 2: Loop Branching
void findSubsets(int index, vector<int> &store, vector<vector<int>> &result, vector<int> &nums)
{
    result.push_back(store);
    for (int i = index; i < nums.size(); i++)
    {
        if (i > index && nums[i] == nums[i - 1]) // Skip the repeating elements
            continue;
        store.push_back(nums[i]);
        findSubsets(i + 1, store, result, nums);
        store.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end()); // critical step

    vector<vector<int>> result;
    vector<int> store;

    findSubsets(0, store, result, nums);
    return result;
}

int main()
{
    vector<int> nums = {2, 2, 2, 3};
    vector<vector<int>> result = subsetsWithDup(nums);

    for (vector<int> v : result)
    {
        for (int n : v)
            cout << n << " ";
        cout << endl;
    }
}