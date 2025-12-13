#include <bits/stdc++.h>
using namespace std;

//$ Intuition can be taken from iterative method
bool isPalindrome(char *str, int start, int end)
{
    if (start >= end)
        return true;

    if (str[start] != str[end])
        return false;

    return isPalindrome(str, start + 1, end - 1);
}

int main()
{
    char str[] = "abcba";
    cout << isPalindrome(str, 0, strlen(str) - 1);
}