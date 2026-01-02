/*
$ LeetCode: 125. Valid Palindrome

A phrase is a palindrome if,
after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

$ Example 1:
# Input: s = "A man, a plan, a canal: Panama"
# Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

$ Example 2:
# Input: s = "race a car"
# Output: false
Explanation: "raceacar" is not a palindrome.

$ Example 3:
# Input: s = " "
# Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int left = 0;
    int right = s.length() - 1;
    while (left < right)
    {
        while (left < right && !isalnum(s[left]))
            left++;

        while (left < right && !isalnum(s[right]))
            right--;

        if (left < right && tolower(s[left]) != tolower(s[right]))
            return false;

        left++;
        right--;
    }
    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    bool result = isPalindrome(s);
    cout << result;
}