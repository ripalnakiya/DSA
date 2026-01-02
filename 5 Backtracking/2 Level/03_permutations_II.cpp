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
        // Skip if this number is already used in current permutation
        if (used[i])
            continue;

        // Skip duplicates:
        // If the current number is the same as the previous one,
        // and the previous one has NOT been used in the current permutation path,
        // then choosing this number would start a duplicate permutation subtree.
        // So we skip it.
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            continue;
        // If we reach here, either this number is not a duplicate,
        // or the previous identical number is already used in this permutation.
        // That means extending the current path is valid and unique.

        store.push_back(nums[i]);
        used[i] = true;

        makePermutations(used, store, result, nums);

        used[i] = false;
        store.pop_back();
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<int> store;
    vector<vector<int>> result;
    vector<bool> used(nums.size(), false);
    makePermutations(used, store, result, nums);
    return result;
}

int main()
{
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result = permute(nums);

    for (vector<int> v : result)
    {
        for (int n : v)
            cout << n << " ";
        cout << endl;
    }
}