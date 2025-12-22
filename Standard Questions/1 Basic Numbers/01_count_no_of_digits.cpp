#include <iostream>
#include <math.h>
using namespace std;

//$ Iterative Approach
int countDigitsI(int num)
{
    int count = 0;
    while(num != 0)
    {
        count++;
        num = num / 10;
    }
    return count;
}

//$ Recursive Approach
int countDigitsR(int num)
{
    if (num <= 0)
        return 0;
    return 1 + countDigitsR(num / 10);
}

//$ Logrithmic Approach 1
int countDigitsL1(int num)
{
    return floor(log10(num)) + 1;
}

//$ Logrithmic Approach 1
int countDigitsL2(int num)
{
    return (int) log10(num) + 1;
}

int main()
{
    int num = 2321;
    cout << countDigitsI(num) << endl;
    cout << countDigitsR(num) << endl;
    cout << countDigitsL1(num) << endl;
    cout << countDigitsL2(num) << endl;
}