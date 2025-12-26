/*
$ LeetCode: 39

Given an array of distinct unsorted integers candidates and a target integer,
return a list of all unique combinations of candidates where the chosen numbers sum to target.
You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times.
Two combinations are unique if the frequency of at least one of the chosen numbers is different.
*/

/*
# Input: candidates = [2,3,6,7], target = 7
# Output: [[2,2,3],[7]]
! Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
*/

/*
# Input: candidates = [2,3,5], target = 8
# Output: [[2,2,2,2],[2,3,3],[3,5]]
*/

#include <bits/stdc++.h>
using namespace std;

//@ Approach 1: Take / Not Take
void findCombinations(int index, int target, vector<int> &store, vector<vector<int>> &result, vector<int> &candidates)
{
    if (target == 0)
    {
        result.push_back(store);
        return;
    }
    if (target < 0 || index == candidates.size())
        return;

    store.push_back(candidates[index]);
    findCombinations(index, target - candidates[index], store, result, candidates);
    store.pop_back();

    findCombinations(index + 1, target, store, result, candidates);
}

//@ Approach 2: Loop Branching
void findCombinations(int index, int target, vector<int> &store, vector<vector<int>> &result, vector<int> &candidates)
{
    if (target == 0)
    {
        result.push_back(store);
        return;
    }
    if (target < 0 || index == candidates.size())
        return;

    for (int i = index; i < candidates.size(); i++)
    {
        store.push_back(candidates[i]);
        findCombinations(i, target - candidates[i], store, result, candidates);
        store.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> store;
    vector<vector<int>> result;
    findCombinations(0, target, store, result, candidates);
    return result;
}

int main()
{
    vector<int> candidates = {2, 6, 3, 7};
    int target = 7;
    vector<vector<int>> result = combinationSum(candidates, target);

    for (vector<int> v : result)
    {
        for (int n : v)
            cout << n << " ";
        cout << endl;
    }
}