/*
$ Shortest Word Distance

You are given an array of strings wordsDict and two different strings word1 and word2.

Return the shortest distance between word1 and word2 in the array.

The distance between two words is defined as the absolute difference of their indices in the array.

$ Example 1:
# Input: wordsDict = ["practice","makes","perfect","coding","makes"]
word1 = "coding"
word2 = "practice"
# Output: 3

$ Example 2:
# Input: wordsDict = ["practice","makes","perfect","coding","makes"]
word1 = "makes"
word2 = "coding"
# Output: 1

Can you solve this in one pass and O(1) extra space?
*/

#include <bits/stdc++.h>
using namespace std;

int shortestWordDistance(vector<string> &wordsDict, string &word1, string &word2)
{
    int lastWord1Index = -1;
    int lastWord2Index = -1;
    int minDistance = INT_MAX;

    for (int i = 0; i < wordsDict.size(); i++)
    {
        if (wordsDict[i] == word1)
            lastWord1Index = i;
        else if (wordsDict[i] == word2)
            lastWord2Index = i;

        if (lastWord1Index != -1 && lastWord2Index != -1)
            minDistance = min(minDistance, abs(lastWord1Index - lastWord2Index));
    }

    return minDistance;
}

int main()
{
    vector<string> wordsDict = {"practice", "makes", "perfect", "coding", "makes"};
    string word1 = "makes";
    string word2 = "coding";

    int result = shortestWordDistance(wordsDict, word1, word2);
    cout << result;
}