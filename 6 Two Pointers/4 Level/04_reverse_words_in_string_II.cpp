/*
$ Reverse Words in a String II

Given a character array s, reverse the order of the words in-place.

A word is defined as a sequence of non-space characters.
The input string:
does not contain leading or trailing spaces
words are separated by exactly one space
You must modify the input array directly using O(1) extra space.

$ Example 1
# Input: s =    ['t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e']
# Output:       ['b','l','u','e',' ','i','s',' ','s','k','y',' ','t','h','e']

$ Example 2
# Input: s = ['a']
# Output: ['a']
*/

/*
! Core Idea:
    Try directly swapping the last character with first character...    "eulb si yks eht"

    Now if we reverse each word individually, we'll get the output we want... "blue is sky the"
*/

#include <bits/stdc++.h>
using namespace std;

void reverse(string &s, int start, int end)
{
    while (start < end)
        swap(s[start++], s[end--]);
}

void reverseWordsII(string &s)
{
    int n = s.length();

    // Reverse complete string
    reverse(s, 0, n - 1);

    // Reverse each word
    int start = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i == n || s[i] == ' ')
        {
            int end = i - 1;
            reverse(s, start, end);
            start = i + 1;
        }
    }
}

int main()
{
    string s = "the sky is blue";
    reverseWordsII(s);
    cout << s << endl;
}