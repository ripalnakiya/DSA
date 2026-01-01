/*
$ 509. Fibonacci Number
*/

#include <bits/stdc++.h>
using namespace std;

//! We has used Memoisation here (Dynamic Approach)
int generateFib(int n, vector<int> &values)
{
    if (n <= 1)
        return n;

    if (values[n - 1] == -1)
        values[n - 1] = generateFib(n - 1, values);

    if (values[n - 2] == -1)
        values[n - 2] = generateFib(n - 2, values);

    return values[n - 1] + values[n - 2];
}
//@ This function has time complexity O(N)

int fib(int n)
{
    vector<int> values(n, -1);
    return generateFib(n, values);
}

int main()
{
    int n = 4;
    cout << fib(n);
}