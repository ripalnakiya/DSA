//$ Program to print only the first occuring subsequence
#include <bits/stdc++.h>
using namespace std;

bool subsequences(int index, int sum, int k, vector<int> &ds, vector<int> &arr)
{
    if (index >= arr.size())
    {
        if (sum == 2)
        {
            for (int x : ds)
                cout << x << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    ds.push_back(arr[index]);
    sum += arr[index];
    //! These if conditions ensures that if, a sequence has already found (true) then don't go further and return from here
    if (subsequences(index + 1, sum, k, ds, arr) == true)
        return true;

    ds.pop_back();
    sum -= arr[index];

    //! These if conditions ensures that if, a sequence has already found (true) then don't go further and return from here
    if (subsequences(index + 1, sum, k, ds, arr) == true)
        return true;

    return false;
}

int main()
{
    vector<int> arr = {1, 2, 1};

    int k = 2; // sum limit

    vector<int> ds;
    int sum = 0; // To keep record of current sum

    int index = 0; // start index

    subsequences(index, sum, k, ds, arr);
    return 0;
}
