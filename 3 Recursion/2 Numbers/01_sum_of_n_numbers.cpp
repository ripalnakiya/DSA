#include <iostream>
using namespace std;

//! For large of value of n, this function may cause stack overflow
//# So, we can use sum of n numbers formula in that case, num * (num + 1) / 2

int sum(int num)
{
    if (num <= 0)
        return 0;

    return num + sum(num-1);
}

int main()
{
    cout << sum(5);
}