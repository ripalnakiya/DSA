/*
$ LeetCode: 7
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1],
then return 0.
*/

#include <iostream>
using namespace std;

int reverse(int num)
{
    int result = 0;

    while (num)
    {
        int digit = num % 10;

        // We want that, if 
        //# result * 10 > INT32_MAX
        //# result * 10 < INT32_MIN
        // then return 0

        // So we modify the condition, such that if
        //# result > INT32_MAX / 10
        //# result < INT32_MIN / 10
        // then return 0

        if ((result > INT32_MAX / 10) || (result < INT32_MIN / 10))
            return 0;

        result = (result * 10) + digit;
        num = num / 10;
    }

    return result;
}

int main()
{
    int num = 2312;
    cout << reverse(num);
}