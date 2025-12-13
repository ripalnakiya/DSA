#include <bits/stdc++.h>
using namespace std;

int findlength(char *str)
{
    if (*str == '\0')
        return 0;
    return 1 + findlength(str + 1);
}

//$ 'str' is the address of the first element of the array
//@ So when we want to reduce down on the size of the array, we'll add 1 to it
//@ so that front element is no longer pointed

int main()
{
    char str[] = "FooBar";
    cout << findlength(str);
}