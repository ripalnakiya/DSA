#include <iostream>
using namespace std;

//$ Program returns Nth fibonacci element

int *series;

int fib(int num)
{
    if (num <= 1)
        return num;
    return fib(num - 1) + fib(num - 2);
}
//@ This function has time complexity O(2^N)

//! We has used Memoisation here (Dynamic Approach)
int optFib(int num)
{
    if (num <= 1)
    {
        series[num] = num;
        return num;
    }

    if (series[num - 1] == 0)
        series[num - 1] = optFib(num - 1);
    if (series[num - 2] == 0)
        series[num - 2] = optFib(num - 2);

    return series[num - 1] + series[num - 2];
}
//@ This function has time complexity O(N)

int main()
{
    series = new int[6]{0};
    cout << optFib(6);
}