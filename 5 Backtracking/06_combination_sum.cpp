/*
$ LeetCode: 39

Given an array of distinct integers candidates and a target integer,
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

void findCombination(int index, int target, vector<int> &store, vector<vector<int>> &result, vector<int> &candidates)
{
    if (index >= candidates.size())
    {
        if (target == 0)
            result.push_back(store);
        return;
    }

    //# Pick the element if it is less than target
    if (candidates[index] <= target)
    {
        store.push_back(candidates[index]);

        // picking the same element, hence index
        // and (target - arr[index])
        findCombination(index, target - candidates[index], store, result, candidates);

        //! Removing the element (For not pick condition)
        store.pop_back();
    }

    //# Not pick the element, hence going for next index and not reducing it from target
    findCombination(index + 1, target, store, result, candidates);
}
//$ Time Complexity = O(2^target * k)
// k for copying the elements from ds to answer

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    vector<int> store;
    vector<vector<int>> result;
    int target = 7;
    findCombination(0, target, store, result, candidates);

    for (vector<int> v : result)
    {
        for (int n : v)
            cout << n << " ";
        cout << endl;
    }
}