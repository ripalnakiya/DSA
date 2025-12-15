#include <iostream>
using namespace std;

int sumI(int num)
{
    int digit, sum = 0;
    while (num != 0)
    {
        digit = num % 10;
        num = num / 10;
        sum += digit;
    }
    return sum;
}

//$ We take intuition from the Iterative method

int sum(int num)
{
    //@ Base Condition : If only one digit is remaining, then return that digit
    if (num / 10 == 0)
        return num % 10;
    return (num % 10) + sum(num / 10);
}

int main()
{
    int num = 2648;
    cout << sumI(num) << endl;
    cout << sum(num) << endl;
}