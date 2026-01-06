/*
$ LeetCode: 942. DI String Match

A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

s[i] == 'I' if perm[i] < perm[i + 1], and
s[i] == 'D' if perm[i] > perm[i + 1].
Given a string s, reconstruct the permutation perm and return it.
If there are multiple valid permutations perm, return any of them.

$ Example 1:
# Input: s = "IDID"
# Output: [0,4,1,3,2]

$ Example 2:
# Input: s = "III"
# Output: [0,1,2,3]

$ Example 3:
# Input: s = "DDI"
# Output: [3,2,0,1]
*/

/*
! Core Idea:
    For 'I', you want the smallest available number now
    For 'D', you want the largest available number now
    Greedy works because only relative order matters
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> diStringMatch(string s)
{
    int n = s.length();

    vector<int> di(n + 1);

    int i = 0;
    int d = n;

    for (int p = 0; p < n; p++)
    {
        if (s[p] == 'I')
            di[p] = i++;
        else
            di[p] = d--;
    }

    // For last remaining number
    di[n] = i;

    return di;
}

int main()
{
    string s = "IDID";
    vector<int> result = diStringMatch(s);

    for (auto &i : result)
        cout << i << " ";
}