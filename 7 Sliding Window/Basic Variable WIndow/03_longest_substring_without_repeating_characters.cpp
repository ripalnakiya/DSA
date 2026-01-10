/*
$ LeetCode: 3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without duplicate characters.

$ Example 1:
# Input: s = "abcabcbb"
# Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

$ Example 2:
# Input: s = "bbbbb"
# Output: 1
Explanation: The answer is "b", with the length of 1.

$ Example 3:
# Input: s = "pwwkew"
# Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <bits/stdc++.h>
using namespace std;

//@ Approach 1: Classic varible sliding window solution
//~ Key Idea: Is this character repeated?
int lengthOfLongestSubstring(string s)
{
    unordered_set<char> seen;

    int low = 0, high = 0;
    int length = 0;
    int maxLength = 0;

    while (high < s.length())
    {
        if (!seen.count(s[high]))
        {
            seen.insert(s[high]);
            length++;
            high++;
            maxLength = max(length, maxLength);
        }
        else
        {
            seen.erase(s[low]);
            length--;
            low++;
        }
    }
    return maxLength;
}

//@ Approach 2: Better Approach
//~ Key Idea: Where was this character last seen?
// (Jump the left pointer directly to the right place when a duplicate appears)
int lengthOfLongestSubstring(string s)
{
    // stores last seen index of each character
    vector<int> lastSeen(256, -1);

    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < s.length(); right++)
    {
        // If character seen before and is inside current window, then move left (skipping elements upto repeating character)
        if (lastSeen[s[right]] >= left)
            left = lastSeen[s[right]] + 1;

        lastSeen[s[right]] = right;
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
}
// This approach removes characters until the duplicate is gone in one go

int main()
{
    string s = "pwwkew";

    int result = lengthOfLongestSubstring(s);

    cout << result;
}