#include <bits/stdc++.h>
using namespace std;

void permutations(int index, vector<vector<int>> &answer, vector<int> &arr)
{
    if (index >= arr.size())
    {
        answer.push_back(arr);
        return;
    }

    for (int i = index; i < arr.size(); ++i)
    {
        swap(arr[index], arr[i]);
        permutations(index + 1, answer, arr);
        swap(arr[index], arr[i]);
    }
    //! We are making permutation call for each index(position)
    //@ So that we can assign a different value for each position
}

int main()
{
    vector<int> arr = {1, 2, 3};

    vector<vector<int>> answer;

    permutations(0, answer, arr);

    for (vector<int> ds : answer)
    {
        for (int x : ds)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}