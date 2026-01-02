/*
$ LeetCode: 2810. Faulty Keyboard

Your laptop keyboard is faulty,
and whenever you type a character 'i' on it,
it reverses the string that you have written.
Typing other characters works as expected.

You are given a 0-indexed string s, and you type each character of s using your faulty keyboard.

Return the final string that will be present on your laptop screen.

$ Example 1:
# Input: s = "string"
# Output: "rtsng"
Explanation:
After typing first character, the text on the screen is "s".
After the second character, the text is "st".
After the third character, the text is "str".
Since the fourth character is an 'i', the text gets reversed and becomes "rts".
After the fifth character, the text is "rtsn".
After the sixth character, the text is "rtsng".
Therefore, we return "rtsng".

$ Example 2:
# Input: s = "poiinter"
# Output: "ponter"
*/

#include <bits/stdc++.h>
using namespace std;

string finalString(string s)
{
    string result;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'i')
        {
            int left = 0;
            int right = result.length() - 1;

            while (left < right)
                swap(result[left++], result[right--]);
        }
        else
        {
            result.push_back(s[i]);
        }
    }
    return result;
}

int main()
{
    string s = "string";
    string result = finalString(s);
    cout << result;
}