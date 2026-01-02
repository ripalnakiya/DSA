/*
$ 917. Reverse Only Letters

Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.

$ Example 1:
# Input: s = "ab-cd"
# Output: "dc-ba"

$ Example 2:
# Input: s = "a-bC-dEf-ghIj"
# Output: "j-Ih-gfE-dCba"

$ Example 3:
# Input: s = "Test1ng-Leet=code-Q!"
# Output: "Qedo1ct-eeLg=ntse-T!"
*/

#include <bits/stdc++.h>
using namespace std;

string reverseOnlyLetters(string s)
{
    int left = 0, right = s.size() - 1;
    while (left < right)
    {
        // Find alphabet from left
        while (left < right && !isalpha(s[left]))
            left++;

        // Find alphabet from right
        while (left < right && !isalpha(s[right]))
            right--;

        // Swap them, and move to next index
        if (left < right)
            swap(s[left++], s[right--]);
    }
    return s;
}

int main()
{
    string s = "Test1ng-Leet=code-Q!";
    string result = reverseOnlyLetters(s);
    cout << result;
}