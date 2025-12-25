#include <bits/stdc++.h>
using namespace std;

void makePermutations(int index, vector<vector<int>> &result, vector<int> &nums)
{
    if (index == nums.size())
    {
        result.push_back(nums);
        return;
    }

    // each element replaces itself with index 0: [1,2,3] : (1,2,3) (2,1,3) (3,2,1)
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        makePermutations(index + 1, result, nums);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;
    makePermutations(0, result, nums);
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