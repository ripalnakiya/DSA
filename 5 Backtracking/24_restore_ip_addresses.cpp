/*
$ LeetCode: 93. Restore IP Addresses
*/

#include <bits/stdc++.h>
using namespace std;

bool isValidIpPart(string &s, int start, int end) {
    string sub = s.substr(start, end - start + 1);

    // Skip parts with leading 0 (Individual 0 is valid)
    if (sub.length() > 1 && sub[0] == '0')
        return false;

    // substring value should not be more than 255
    int num = 0;
    for (char c : sub)
        num = num * 10 + (c - '0');
    if (num > 255)
        return false;

    return true;
}

void restoreIp(int index, int partCompleted, string &store, vector<string> &result, string &s) {
    // Pruning Technique: Return if too many character remain, Return if too few characters remain
    int remainingChars = s.length() - index;
    int remainingParts = 4 - partCompleted;

    /*  For Example, Parts done: 2 Remaining parts: 2
    *   That means: Minimum digits left = 2 Maximum digits left = 6
    *
    *   So valid remaining string lengths are: [2, 3, 4, 5, 6]
    *
    *   If remaining string length is: 1, 7, 8 -> then return
    */

    // Valid only if remainingParts ≤ remainingChars ≤ 3 × remainingParts, otherwise return
    if (remainingChars < remainingParts || remainingChars > remainingParts * 3)
        return;

    if (partCompleted == 3) {   // Include the remaining number directly, coz it's last part
        if (isValidIpPart(s, index, s.length() - 1)) {
            int oldLength = store.length();
            store.append(s.substr(index, s.length() - 1 - index + 1));
            result.push_back(store);
            store.resize(oldLength);
        }
        return;
    }

    for (int i = index; i < (index + 3) && i < s.length(); i++) {
        if (isValidIpPart(s, index, i)) {
            int oldLength = store.length();
            store.append(s.substr(index, i - index + 1) + ".");
            restoreIp(i + 1, partCompleted + 1, store, result, s);
            store.resize(oldLength);
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    string store = "";
    vector<string> result;
    restoreIp(0, 0, store, result, s);
    return result;
}

int main() {
    string s = "101023";
    vector<string> result = restoreIpAddresses(s);

    for (auto &i : result) {
        cout << i << endl;
    }
}