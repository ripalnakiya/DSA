#include <iostream>
using namespace std;

int exponent(int num, int pow)
{
    if (pow <= 0)
        return 1;
    return num * exponent(num, pow - 1);
}
//@ This function makes more number of calls

int optExponent(int num, int pow)
{
    if (pow == 0)
        return 1;
    if (pow % 2 == 0)
        return optExponent(num * num, pow / 2);
    else
        return optExponent(num * num, (pow - 1) / 2) * num;
}
//@ This function makes less number of calls

int main()
{
    cout << optExponent(2, 9);
}