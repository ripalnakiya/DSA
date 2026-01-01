/*
$ LeetCode: 784. Letter Case Permutation

Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. Return the output in any order.

$ Example 1:
# Input: s = "a1b2"
# Output: ["a1b2","a1B2","A1b2","A1B2"]

$ Example 2:
# Input: s = "3z4"
# Output: ["3z4","3Z4"]
*/

#include <bits/stdc++.h>
using namespace std;

//@ Appraoch 1: Take / Not Take : Small / Capital letter
void generatePermutations(int index, string &store, vector<string> &result, string s)
{
    if (store.length() == s.length())
    {
        result.push_back(store);
        return;
    }

    if (isalpha(s[index]))
    {
        store.push_back(toupper(s[index]));
        generatePermutations(index + 1, store, result, s);
        store.pop_back();

        store.push_back(tolower(s[index]));
        generatePermutations(index + 1, store, result, s);
        store.pop_back();
    }
    else
    {
        store.push_back(s[index]);
        generatePermutations(index + 1, store, result, s);
        store.pop_back();
    }
}

//@ Approach 2: Branch Looping
void generatePermutations(int index, string &store, vector<string> &result, string s)
{
    result.push_back(store);

    for (int i = index; i < s.length(); i++)
    {
        if (isdigit(s[i]))
            continue;

        // Flip the case
        bool isUpper = isupper(s[i]);
        store[i] = isUpper ? tolower(s[i]) : toupper(s[i]);

        generatePermutations(i + 1, store, result, s);

        store[i] = s[i];
    }
}

vector<string> letterCasePermutation(string s)
{
    vector<string> result;
    string store = s;
    generatePermutations(0, store, result, s);
    return result;
}

int main()
{
    string s = "a1b2";
    vector<string> result = letterCasePermutation(s);

    for (auto &i : result)
    {
        cout << i << endl;
    }
}