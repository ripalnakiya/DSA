#include <bits/stdc++.h>
using namespace std;

void permutations(int *freq, vector<int> &ds, vector<vector<int>> &answer, vector<int> &arr)
{
    if (ds.size() == arr.size())
    {
        answer.push_back(ds);
        return;
    }

    for (int i = 0; i < arr.size(); ++i)
    {
        if (!freq[i])
        {
            freq[i] = 1;
            ds.push_back(arr[i]);
            permutations(freq, ds, answer, arr);
            ds.pop_back();
            freq[i] = 0;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};

    vector<int> ds;
    vector<vector<int>> answer;

    int freq[3] = {0};

    permutations(freq, ds, answer, arr);

    for (vector<int> ds : answer)
    {
        for (int x : ds)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}

//$ In this approach, we have used frequency array, to keep track of the selected elements
//$ So this increases the space complexity