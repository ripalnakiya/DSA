/*
$ LeetCode: 844. Backspace String Compare

Given two strings s and t,
return true if they are equal when both are typed into empty text editors.
'#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

$ Example 1:
# Input: s = "ab#c", t = "ad#c"
# Output: true
Explanation: Both s and t become "ac".

$ Example 2:
# Input: s = "ab##", t = "c#d#"
# Output: true
Explanation: Both s and t become "".

$ Example 3:
# Input: s = "a#c", t = "b"
# Output: false
Explanation: s becomes "c" while t becomes "b".

$ Example 4:
# Input: s = "nzp#o#g", t = "b#nzp#o#g"
# Output: true

$ Example 5:
# Input: s = y#fo##f, t = y#f#o##f
# Output: true
*/

#include <bits/stdc++.h>
using namespace std;

int nextValidIndex(int index, string &str)
{
    int backspaces = 0;

    while (index >= 0)
    {
        if (str[index] == '#')
        {
            backspaces++;
            index--;
        }
        else if (backspaces > 0)
        {
            backspaces--;
            index--;
        }
        else
        {
            break;
        }
    }
    return index;
}

bool backspaceCompare(string s, string t)
{
    int i = s.length() - 1, j = t.length() - 1;

    while (i >= 0 || j >= 0)
    {
        i = nextValidIndex(i, s);
        j = nextValidIndex(j, t);

        bool isValidI = (i >= 0);
        bool isValidJ = (j >= 0);

        // If two actual characters are different
        if (isValidI && isValidJ && s[i] != t[j])
            return false;

        // If expecting to compare char vs nothing
        if (isValidI != isValidJ)
            return false;
        // If one index is valid and another is invalid, Then return
        // valid + valid        = skip return
        // valid + invalid      = return
        // invalid + valid      = return
        // invalid + invalid    = will be terminated by while loop

        i--;
        j--;
    }
    return true;
}

int main()
{
    string s = "nzp#o#g";
    string t = "b#nzp#o#g";

    bool result = backspaceCompare(s, t);

    cout << result;
}