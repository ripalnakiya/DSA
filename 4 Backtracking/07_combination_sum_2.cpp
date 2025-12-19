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

//! Approach 1 - Brute Force
// Take intuition from combination sum 1, sort the candidates list and use set to have unique solutions 
// Time Complexity = O(2^target * log N * k )
// log N for copying the elements in a Set
// k for converting a Set into a vector of vector (to return the answer)

// We're generating duplicate combinations on purpose and then cleaning the mess later
// That’s like cooking five dishes, dropping two on the floor, then saying “don’t worry, I filtered them out.”

#include <bits/stdc++.h>
using namespace std;

void findCombination(int index, int target, vector<int> &store, set<vector<int>> &uniqueResult, vector<int> &candidates)
{
    // Base case
    if (target == 0)
    {
        uniqueResult.insert(store); // set removes duplicates
        return;
    }

    if (index >= candidates.size() || target < 0)
        return;

    // Pick the element (ONLY ONCE, so index + 1)
    if (candidates[index] <= target)
    {
        store.push_back(candidates[index]);
        findCombination(index + 1, target - candidates[index], store, uniqueResult, candidates);
        store.pop_back();
    }

    // Not pick the element
    findCombination(index + 1, target, store, uniqueResult, candidates);
}

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    // Sort so same combinations look identical before going into set
    sort(candidates.begin(), candidates.end());

    set<vector<int>> uniqueResult;
    vector<int> store;

    findCombination(0, target, store, uniqueResult, candidates);

    // Convert set to output
    for (auto &combination : uniqueResult)
    {
        for (int num : combination)
            cout << num << " ";
        cout << endl;
    }
}