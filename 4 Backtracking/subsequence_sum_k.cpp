//$ Program to find all the subsequences with sum k
#include <bits/stdc++.h>
using namespace std;

void subsequences(int index, int sum, int k, vector<int> &ds, vector<int> &arr)
{

    if (index >= arr.size())
    {
        if (sum == 2)
        {
            for (int x : ds)
                cout << x << " ";
            cout << endl;
        }
        return;
    }

    ds.push_back(arr[index]);
    sum += arr[index];
    subsequences(index + 1, sum, k, ds, arr);

    ds.pop_back();
    sum -= arr[index];

    subsequences(index + 1, sum, k, ds, arr);
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
