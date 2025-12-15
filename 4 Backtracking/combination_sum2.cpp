//$ Program to find all possible combinations that gives target value on adding
//$ Each element can be used only once in a combination
//$ Solution combination should be in sorted order
//$ Solution should not contain duplicate combinations

// # For example, target = 4
// # arr[] = {1,1,1,2,2}
//! Solution = [[1,1,2], [2,2]];
//~ We cannot have solution [1,2,1] because after sorting it, we'll get a duplicate combination
#include <bits/stdc++.h>
using namespace std;

void combinationSum(int index, int target, vector<int> &ds, vector<vector<int>> &answer, vector<int> &arr)
{
    if (target == 0)
    {
        answer.push_back(ds);
        return;
    }
    for (int i = index; i < arr.size(); ++i)
    {
        if (i > index && arr[i] == arr[i - 1])
            continue;

        if (arr[i] > target)
            break;

        ds.push_back(arr[i]);
        combinationSum(i + 1, target - arr[i], ds, answer, arr);
        ds.pop_back();
    }
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 2};

    sort(arr.begin(), arr.end());
    vector<int> ds;
    vector<vector<int>> answer;
    int target = 4;

    combinationSum(0, target, ds, answer, arr);

    for (vector<int> ds : answer)
    {
        for (int x : ds)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}

//$ Time Complexity = O(2^n * k)
//! k for copying the elements from ds to answer

//$ When we apply brute force (Method similar to previous combination sum), we get complexity as
//$ Time Complexity = O(2^target * log N * k )
//! log N for copying the elements in a Set answer
//! k for converting a Set into a vector of vector (to return the answer)