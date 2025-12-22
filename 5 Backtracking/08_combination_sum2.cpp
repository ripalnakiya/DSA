#include <bits/stdc++.h>
using namespace std;

void findCombination(int index, int target, vector<int> &store, vector<vector<int>> &result, vector<int> &candidates)
{
    if (target == 0)
    {
        result.push_back(store);
        return;
    }
    for (int i = index; i < candidates.size(); i++)
    {
        //! The only use of index variable is to not skip the current element
        if (i > index && candidates[i] == candidates[i - 1])
            continue;

        if (candidates[i] > target)
            break;
        
        store.push_back(candidates[i]);
        findCombination(i + 1, target - candidates[i], store, result, candidates);
        store.pop_back();
    }
}
//$ Time Complexity = O(2^n * k)
// k for copying the elements from store to result

int main()
{
    vector<int> candidates = {1, 2, 2, 1, 1};
    int target = 4;

    // Sort so same combinations look identical before going into set
    sort(candidates.begin(), candidates.end());

    vector<int> store;
    vector<vector<int>> result;

    findCombination(0, target, store, result, candidates);

    for (vector<int> ds : result)
    {
        for (int x : ds)
            cout << x << " ";
        cout << endl;
    }
}