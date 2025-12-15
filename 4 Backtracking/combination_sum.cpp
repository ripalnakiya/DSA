//$ Program to print all the possible combinations that add up to target value
//$ Each element can be used multiple times in a sequence
#include <bits/stdc++.h>
using namespace std;

void combinationSum(int index, int target, vector<int> &ds, vector<vector<int>> &answer, vector<int> &arr)
{
    if (index >= arr.size())
    {
        if (target == 0)
            answer.push_back(ds);
        return;
    }

    // # Pick the element if it is less than target
    if (arr[index] <= target)
    {
        ds.push_back(arr[index]);
        //! picking the same element, hence index
        //! and (target - arr[index])
        combinationSum(index, target - arr[index], ds, answer, arr);

        //! Removing the element (For not pick condition)
        ds.pop_back();
    }

    // # Not pick the element, hence going for next index and not reducing it from target
    combinationSum(index + 1, target, ds, answer, arr);
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};

    int target = 7;
    vector<vector<int>> answer;
    vector<int> ds;

    combinationSum(0, target, ds, answer, arr);

    for (vector<int> ds : answer)
    {
        for (int x : ds)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}

//$ Time Complexity = O(2^target * k)
//! k for copying the elements from ds to answer