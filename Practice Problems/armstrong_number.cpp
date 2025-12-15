#include <iostream>
using namespace std;

int pow(int num, int power)
{
    int result = 1;
    while (power)
    {
        result = result * num;
        power--;
    }
    return result;
}

int main()
{
    int num, digit, count = 0, sum = 0, n;
    cout << "\nEnter a number: ";
    cin >> num;

    n = num;

    while (n > 0)
    {
        digit = n % 10;
        n = n / 10;
        count++;
    }

    n = num;

    while (n > 0)
    {
        digit = n % 10;
        n = n / 10;
        sum = sum + pow(digit, count);
    }

    if (sum == num)
        cout << "\nArmstrong Number";
    else
        cout << "\nNot Armstrong Number";

    return 0;
}
