/*
$ LeetCode: 1768. Merge Strings Alternately

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order,
starting with word1. If a string is longer than the other,
append the additional letters onto the end of the merged string.

Return the merged string.

$ Example 1:
# Input: word1 = "abc", word2 = "pqr"
# Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r

$ Example 2:
# Input: word1 = "ab", word2 = "pqrs"
# Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b
word2:    p   q   r   s
merged: a p b q   r   s

$ Example 3:
# Input: word1 = "abcd", word2 = "pq"
# Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q
merged: a p b q c   d
*/

#include <bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2)
{
    string result;
    int first = 0, second = 0;
    while (first < word1.length() && second < word2.length())
    {
        if (first <= second)
            result.push_back(word1[first++]);
        else
            result.push_back(word2[second++]);
    }

    while (first < word1.length())
        result.push_back(word1[first++]);

    while (second < word2.length())
        result.push_back(word2[second++]);

    return result;
}

int main()
{
    string word1 = "abcd";
    string word2 = "pq";
    string result = mergeAlternately(word1, word2);
    cout << result;
}