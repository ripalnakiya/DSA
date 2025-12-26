/*
$ LeetCode: 40

Given a collection of candidate numbers (candidates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
*/

/*
# Input: candidates = [10,1,2,7,6,1,5], target = 8
# Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
*/

/*
# Input: candidates = [1,1,1,2,2] , target = 4
# Output: [[1,1,2], [2,2]]
~ We cannot have solution [1,2,1] because after sorting it, we'll get a duplicate combination
*/

#include <bits/stdc++.h>
using namespace std;

//@ Approach 0: Brute Force
// Take intuition from combination sum 1, sort the candidates list and use set to have unique solutions
// Time Complexity = O(2^target * log N * k )
// log N for copying the elements in a Set
// k for converting a Set into a vector of vector (to return the answer)

// We're generating duplicate combinations on purpose and then cleaning the mess later
// That’s like cooking five dishes, dropping two on the floor, then saying “don’t worry, I filtered them out.”

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
    findCombinations(index + 1, target - candidates[index], store, result, candidates);
    store.pop_back();

    int nextIndex = index + 1;
    while (nextIndex < candidates.size() && candidates[index] == candidates[nextIndex])
        nextIndex++;

    findCombinations(nextIndex, target, store, result, candidates);
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
        if (i > index && candidates[i] == candidates[i - 1])
            continue;

        store.push_back(candidates[i]);
        findCombinations(i + 1, target - candidates[i], store, result, candidates);
        store.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<int> store;
    vector<vector<int>> result;
    findCombinations(0, target, store, result, candidates);
    return result;
}

int main()
{
    vector<int> candidates = {2, 5, 2, 1, 2};
    int target = 5;
    vector<vector<int>> result = combinationSum2(candidates, target);

    for (vector<int> v : result)
    {
        for (int n : v)
            cout << n << " ";
        cout << endl;
    }
}