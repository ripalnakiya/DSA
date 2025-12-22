#include <bits/stdc++.h>
using namespace std;

//$ Program to find all the unique subsets of an array

void findSubsets(int index, vector<int> &ds, vector<vector<int>> &answer, vector<int> &arr)
{
    answer.push_back(ds);

    for (int i = index; i < arr.size(); ++i)
    {

        if (i > index && arr[i] == arr[i - 1])
            continue;

        ds.push_back(arr[i]);
        findSubsets(i + 1, ds, answer, arr);
        ds.pop_back();
    }
}

int main()
{
    //    vector<int> arr = {1, 2, 2, 2, 3, 3};
    vector<int> arr = {1, 2, 2};

    vector<int> ds;
    vector<vector<int>> answer;

    findSubsets(0, ds, answer, arr);

    for (vector<int> ds : answer)
    {
        for (int x : ds)
            cout << x << " ";
        cout << endl;
    }

    // solution should include
    // {}, {1}, {1 2}, {1 2 2}, {2}, {2 2}
    // It should not repeate {1 2} and {2}
    return 0;
}