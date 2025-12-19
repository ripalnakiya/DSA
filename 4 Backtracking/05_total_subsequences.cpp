#include <bits/stdc++.h>
using namespace std;

//$ Count the total number of subsequences that satisfy the given condition

int subsequences(int index, int &sum, vector<int> &list, int &k)
{
    if(index >= list.size())
    {
        if (sum == k)
            return 1;
        return 0;
    }

    sum += list[index];
    int left = subsequences(index + 1, sum, list, k);

    sum -= list[index];
    int right = subsequences(index + 1, sum, list ,k);

    return left + right;
}

int main()
{
    vector<int> list = {1, 2, 1};
    int sum = 0;
    int k = 2;

    cout << subsequences(0, sum, list, k);
}