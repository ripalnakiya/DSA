/*
$ LeetCode: 345. Reverse Vowels of a String
*/

#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

string reverseVowels(string s)
{
    int left = 0, right = s.size() - 1;

    while (left < right)
    {
        // Move left pointer until it hits a vowel
        while (left < right && !isVowel(s[left]))
            left++;

        // Move right pointer until it hits a vowel
        while (left < right && !isVowel(s[right]))
            right--;

        // Swap and move to next indices
        if (left < right)
            swap(s[left++], s[right--]);
    }
    return s;
}
//~ Time Complexity: O(n)
//~ Space Complexity: O(1)

int main()
{
    string s = "IceCreAm";
    string result = reverseVowels(s);
    cout << result;
}