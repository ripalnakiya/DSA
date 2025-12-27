/*
$ LeedCode: 77. Combinations

Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

# Input: n = 4, k = 2
# Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
*/

#include <bits/stdc++.h>
using namespace std;

void findCombinations(int start, vector<int> &store, vector<vector<int>> &result, int n, int k)
{
    if (store.size() == k)
    {
        result.push_back(store);
        return;
    }

    // for size k = 2, we should never include 4, coz it doesn't have further number to include.
    int dontCheckLastOnes = k - store.size();
    for (int number = start; number <= n - dontCheckLastOnes + 1; number++)
    {
        store.push_back(number);
        findCombinations(number + 1, store, result, n, k);
        store.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> result;
    vector<int> store;
    findCombinations(1, store, result, n, k);
    return result;
}

int main()
{
    int n = 4, k = 2;
    vector<vector<int>> result = combine(n, k);

    for (vector<int> v : result)
    {
        for (int n : v)
            cout << n << " ";
        cout << endl;
    }
}