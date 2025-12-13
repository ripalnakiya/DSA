#include <iostream>
using namespace std;

int convertI(int num)
{
    int binDigit, bin = 0, multiplier = 1;
    while (num != 0)
    {
        binDigit = num % 2;
        num = num / 2;
        bin = bin + (binDigit * multiplier);    // New digit has to be placed at next higher level
        multiplier *= 10;
    }
    return bin;
}

//$ We take intuition from the Iterative method

int convert(int num)
{
    if (num == 0)
        return 0;

    int binDigit = num % 2;

    int bin = convert(num / 2);
    
    //# We perform the operation during descending phase of recursion
    return (bin * 10) + binDigit;
}

int main()
{
    int num = 22;
    cout << convertI(num) << endl;
    cout << convert(num) << endl;
}