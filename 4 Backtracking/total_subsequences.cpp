//$ Program to find total number of subsequences satisfying a given condition
//$ Each element can be used only once in a sequence
#include <bits/stdc++.h>
using namespace std;

int subsequences(int index, int sum, int k, vector<int> &arr)
{

    if (index >= arr.size())
    {
        if (sum == 2)
            return 1;
        return 0;
    }

    sum += arr[index];
    int left = subsequences(index + 1, sum, k, arr);

    sum -= arr[index];
    int right = subsequences(index + 1, sum, k, arr);

    return left + right;
}

int main()
{
    vector<int> arr = {1, 2, 1};

    int k = 2; // sum limit

    int sum = 0; // To keep record of current sum

    int index = 0; // start index

    cout << subsequences(index, sum, k, arr);
    return 0;
}
