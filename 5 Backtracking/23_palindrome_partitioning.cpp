/*
$ LeetCode: 131. Palindrome Partitioning
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int start, int end) {
    while (start < end) 
        if (s[start++] != s[end--]) 
            return false;
    return true;
}

void solve(int index, vector<string> &store, vector<vector<string>> &result, string &s) {
    if (index == s.length()) {
        result.push_back(store);
        return;
    }

    for (int i = index; i < s.length(); i++) {
        if (isPalindrome(s, index, i)) {
            store.push_back(s.substr(index, i - index + 1));
            solve(i + 1, store, result, s);
            store.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<string> store;
    vector<vector<string>> result;
    solve(0, store, result, s);
    return result;
}

int main() {
    string s = "aaab";
    vector<vector<string>> result = partition(s);

    for (auto &i : result) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    // [["a","a","a","b"],
    // ["a","aa","b"],
    // ["aa","a","b"],
    // ["aaa","b"]]
}