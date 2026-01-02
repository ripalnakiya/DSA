#include <iostream>
using namespace std;

int reverseNumberI(int num)
{
    int digit, reverse = 0;
    while (num!=0)
    {
        digit = num % 10;
        num = num / 10;
        reverse = (reverse * 10) + digit;
    }
}

//$ We take intuition from the Iterative method

int reverseNumber(int num, int reverse)
{
    if(num == 0)
        return reverse;

    int digit = num % 10;
    reverse = (reverse * 10) + digit;
    return reverseNumber(num / 10, reverse);
}

int main()
{
    int num = 2648;
    cout << reverseNumberI(num) << endl;
    cout << reverseNumber(num, 0) << endl;
}