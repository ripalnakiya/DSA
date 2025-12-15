#include <bits/stdc++.h>
using namespace std;

void reverseString(char *str)
{
    if (*str == '\0')
    {
        return;
    }
    reverseString(str + 1);
    cout << *str;
}

int main()
{
    char str[] = "FooBar";
    reverseString(str);
}