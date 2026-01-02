/*
$ LeetCode: 541. Reverse String II

Given a string s and an integer k,
reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them.
If there are less than 2k but greater than or equal to k characters,
then reverse the first k characters and leave the other as original.

$ Example 1:
# Input: s = "abcdefg", k = 2
# Output: "bacdfeg"

$ Example 2:
# Input: s = "abcd", k = 2
# Output: "bacd"
*/

#include <bits/stdc++.h>
using namespace std;

string reverseStr(string s, int k)
{
    for (int i = 0; i < s.length(); i += 2 * k)
    {
        int left = i;
        int right = i + k - 1;

        if (right >= s.length())
            right = s.length() - 1;

        while (left < right)
        {
            swap(s[left++], s[right--]);
        }
    }
    return s;
}
//~ Time Complexity: O(n)
//~ Space Complexity: O(1) = in-place operation

int main()
{
    string s = "abcdefg";
    int k = 8;
    string result = reverseStr(s, k);
    cout << result;
}