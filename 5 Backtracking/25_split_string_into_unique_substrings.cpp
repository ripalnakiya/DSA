/*
$ 1593. Split a String Into the Max Number of Unique Substrings
*/

#include <bits/stdc++.h>
using namespace std;

void findSubStrings(int index, int count, int &maximum, set<string> &hash, string &s)
{
    // Prune: If the current count plus remaining characters can't exceed maximum, return
    // (We've used similar pruning technique in restore_ip_addresses.cpp)
    if (count + (s.length() - index) <= maximum)
        return;

    if (index == s.length())
    {
        maximum = max(count, maximum);
        return;
    }

    for (int i = index; i < s.length(); i++)
    {
        string substring = s.substr(index, i - index + 1);
        if (hash.find(substring) == hash.end())
        {
            hash.insert(substring);
            findSubStrings(i + 1, count + 1, maximum, hash, s);
            hash.erase(substring);
        }
    }
}

int maxUniqueSplit(string s)
{
    int maximum = 0;
    int count = 0;
    set<string> hash;
    findSubStrings(0, count, maximum, hash, s);
    return maximum;
}

int main()
{
    string s = "wwwzfvedwfvhsww";
    int result = maxUniqueSplit(s);
    cout << result;
}