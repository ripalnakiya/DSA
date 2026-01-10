/*
$ LeetCode: 1456. Maximum Number of Vowels in a Substring of Given Length

Given a string s and an integer k,
return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

$ Example 1:
# Input: s = "abciiidef", k = 3
# Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

$ Example 2:
# Input: s = "aeiou", k = 2
# Output: 2
Explanation: Any substring of length 2 contains 2 vowels.

$ Example 3:
# Input: s = "leetcode", k = 3
# Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
*/

#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

int maxVowels(string s, int k)
{
    int windowCount = 0;

    // Count vowels in first window
    for (int i = 0; i < k; i++)
        if (isVowel(s[i]))
            windowCount++;

    int maxVowels = windowCount;

    for (int right = k; right < s.length(); right++)
    {
        if (isVowel(s[right]))
            windowCount++;
        if (isVowel(s[right - k]))
            windowCount--;

        maxVowels = max(windowCount, maxVowels);
    }
    return maxVowels;
}

int main()
{
    string s = "leetcode";
    int k = 3;

    int result = maxVowels(s, k);

    cout << result;
}