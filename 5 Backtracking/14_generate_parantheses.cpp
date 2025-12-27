/*
$ LeetCode: 22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

$ Example 1:
# Input: n = 3
# Output: ["((()))","(()())","(())()","()(())","()()()"]

$ Example 2:
# Input: n = 1
# Output: ["()"]
*/

#include <bits/stdc++.h>
using namespace std;

void generate(string &str, int open, int closed, vector<string> &result, int n)
{
    if (str.length() == 2 * n) {
        result.push_back(str);
        return;
    }

    // Add '(' if we still can
    if (open < n) {
        str.push_back('(');
        generate(str, open + 1, closed, result, n);
        str.pop_back();
    }

    // Add ')' only if it won't break validity
    if (closed < open) {
        str.push_back(')');
        generate(str, open, closed + 1, result, n);
        str.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string str = "";
    generate(str, 0, 0, result, n);
    return result;
}

int main() {
    int n = 3;
    vector<string> result = generateParenthesis(n);

    for (auto &v: result) {
        cout << v << endl;
    }
}