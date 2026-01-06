/*
$ LeetCode: 821. Shortest Distance to a Character

Given a string s and a character c that occurs in s,
return an array of integers answer where answer.length == s.length and
answer[i] is the distance from index i to the closest occurrence of character c in s.

The distance between two indices i and j is abs(i - j), where abs is the absolute value function.


$ Example 1:
# Input: s = "loveleetcode", c = "e"
# Output: [3,2,1,0,1,0,0,1,2,2,1,0]
Explanation: The character 'e' appears at indices 3, 5, 6, and 11 (0-indexed).
The closest occurrence of 'e' for index 0 is at index 3, so the distance is abs(0 - 3) = 3.
The closest occurrence of 'e' for index 1 is at index 3, so the distance is abs(1 - 3) = 2.
For index 4, there is a tie between the 'e' at index 3 and the 'e' at index 5, but the distance is still the same: abs(4 - 3) == abs(4 - 5) = 1.
The closest occurrence of 'e' for index 8 is at index 6, so the distance is abs(8 - 6) = 2.

$ Example 2:
# Input: s = "aaab", c = "b"
# Output: [3,2,1,0]
*/

#include <bits/stdc++.h>
using namespace std;

/*
! Approach 1
    For every e, mark the current distance 0
        start one pointer that goes towards left until next e is found
        start one pointer that goes towards right until next e is found
*/
vector<int> shortestToChar(string s, char c)
{
    int n = s.length();

    vector<int> result(n, INT_MAX);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == c)
        {
            result[i] = 0;

            int left = i - 1;
            int lCounter = 1;
            // Keep going left until 0 index or another c is found
            while (left >= 0 && s[left] != c)
            {
                // If new distance from new c is less than previous distance, update it
                if (lCounter < result[left])
                    result[left] = lCounter;
                left--;
                lCounter++;
            }

            int right = i + 1;
            int rCounter = 1;
            // Keep going right until n index or another c is found
            while (right < n && s[right] != c)
            {
                // Since we're moving from left to right,
                // We don't need to care for minimum distance on right pointer
                // Coz iff there existed another c, then it's left pointer will handle the minimum distance
                result[right] = rCounter;
                right++;
                rCounter++;
            }
        }
    }
    return result;
}
//~ Over engineered approach: Worst case time complexity O(n^2)

/*
! Approach 2
    Left to right pass
        Track distance from last seen c
    Right to left pass
        Track distance from next seen c
    For each index, take the minimum of the two
*/
vector<int> shortestToChar(string s, char c)
{
    int n = s.length();

    vector<int> result(n, n);

    int position = -n;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == c)
            position = i;
        result[i] = i - position;
    }

    // Start from last encountered c
    for (int j = position - 1; j >= 0; j--)
    {
        if (s[j] == c)
            position = j;
        result[j] = min(position - j, result[j]);
    }

    return result;
}

int main()
{
    string s = "loveleetcode";
    char c = 'e';
    vector<int> result = shortestToChar(s, c);
    for (auto &i : result)
        cout << i << " ";
}