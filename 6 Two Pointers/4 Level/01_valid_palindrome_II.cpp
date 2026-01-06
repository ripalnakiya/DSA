/*
$ LeetCode: 680. Valid Palindrome II

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

$ Example 1:
# Input: s = "aba"
# Output: true

$ Example 2:
# Input: s = "abca"
# Output: true
Explanation: You could delete the character 'c'.

$ Example 3:
# Input: s = "abc"
# Output: false
*/

/*
! Core Idea:
Can I delete one character so that the rest is a palindrome?
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

bool validPalindrome(string s)
{
    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {
        // Mismatch found, try removing one of the character and see if the remaining string is palindrome
        if (s[left] != s[right])
        {
            bool skipLeft = isPalindrome(s, left, right - 1);
            bool skipRight = isPalindrome(s, left + 1, right);

            // If after skipping either one of the element, string is palidrome, then return true
            if (skipLeft || skipRight)
                return true;
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main()
{
    string s = "abca";
    bool result = validPalindrome(s);
    cout << result;
}