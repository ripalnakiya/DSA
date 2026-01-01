/*
$ LeetCode: 17 Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number could represent. 
Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.

$ Example 1:
# Input: digits = "2"
# Output: ["a","b","c"]

$ Example 2:
# Input: digits = "23"
# Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

$ Example 3:
# Input: digits = "234"
# Output: ["adg", "adh", "adi", "aeg", "aeh", "aei", "afg", "afh", "afi", "bdg", "bdh", "bdi", "beg", "beh", "bei", "bfg", "bfh", "bfi", "cdg", "cdh", "cdi", "ceg", "ceh", "cei", "cfg", "cfh", "cfi"]
*/

#include <bits/stdc++.h>
using namespace std;

void makeCombinations(int num, string &store, vector<string> &result, vector<string> &numpad, string &digits)
{
    if (num == digits.length())
    {
        result.push_back(store);
        return;
    }

    int digit = digits[num] - '0';
    string currentString = numpad[digit];
    for (int i = 0; i < currentString.length(); i++)
    {
        store.push_back(currentString[i]);
        makeCombinations(num + 1, store, result, numpad, digits);
        store.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> numpad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    string store = "";
    makeCombinations(0, store, result, numpad, digits);
    return result;
}

int main()
{
    string digits = "234";
    vector<string> result = letterCombinations(digits);

    for (auto &v : result)
    {
        cout << v << endl;
    }
}
