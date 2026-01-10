/*
$ GeeksForGeeks: Longest Substring with K Uniques

You are given a string s consisting only lowercase alphabets and an integer k.
Your task is to find the length of the longest substring that contains exactly k distinct characters.

If no such substring exists, return -1.

$ Example 1:
# Input: s = "aabacbebebe", k = 3
# Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.

$ Example 2:
# Input: s = "aaaa", k = 2
# Output: -1
Explanation: There's no substring with 2 distinct characters.

$ Example 3:
# Input: s = "aabaaab", k = 2
# Output: 7
Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.

$ Example 1:
# Input: s = "aabbcaebebe", k = 3
# Output: 7
*/

#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string &s, int k)
{
    unordered_map<char, int> freq;
    int maxLength = -1;
    int left = 0;

    for (int right = 0; right < s.length(); right++)
    {
        freq[s[right]]++;

        while (freq.size() > k)
        {
            freq[s[left]]--;

            if (freq[s[left]] == 0)
                freq.erase(s[left]);

            left++;
        }

        if (freq.size() == k)
            maxLength = max(right - left + 1, maxLength);
    }

    return maxLength;
}

int main()
{
    string s = "aabbcaebebee";
    int k = 3;

    int result = longestKSubstr(s, k);

    cout << result;
}