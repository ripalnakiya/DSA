//$ Program to find sum of each subset of an array
#include <bits/stdc++.h>
using namespace std;

void subsetSum(int index, int sum, vector<int> &solution, vector<int> &arr)
{
    //! When index exceeds the array range, then add the sum in solution and then return
    if (index == arr.size())
    {
        solution.push_back(sum);
        return;
    }

    //! pick the element
    subsetSum(index + 1, sum + arr[index], solution, arr);

    //! not pick the element
    subsetSum(index + 1, sum, solution, arr);
}

int main()
{
    vector<int> arr = {3, 1, 2};

    vector<int> solution;
    int sum = 0;

    subsetSum(0, sum, solution, arr);

    sort(solution.begin(), solution.end());

    for (int x : solution)
    {
        cout << x << " ";
    }
    return 0;
}