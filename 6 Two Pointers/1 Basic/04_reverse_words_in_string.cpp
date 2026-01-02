/*
$ LeetCode: 557. Reverse Words in a String III

Given a string s,
reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

$ Example 1:
# Input: s = "Let's take LeetCode contest"
# Output: "s'teL ekat edoCteeL tsetnoc"
*/

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    int start = 0;
    for (int i = 0; i <= s.length(); i++)
    {
        if (i == s.length() || s[i] == ' ')
        {
            int left = start;
            int right = i - 1;

            while (left < right)
                swap(s[left++], s[right--]);

            start = i + 1; // next word starts after space
        }
    }
    return s;
}

int main()
{
    string s = "Let's take LeetCode contest";
    string result = reverseWords(s);
    cout << result;
}