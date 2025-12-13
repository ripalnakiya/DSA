#include <bits/stdc++.h>
using namespace std;

//@ My Approach
void findOccurrences(string str, char ch, int i, int &first, int &last)
{
    if (i == str.size())
        return;
    
    if (str[i] == ch && first == -1)
        first = i;
    
    findOccurrences(str, ch, i + 1, first, last);

    if (str[i] == ch && last == -1)
        last = i;
}
//! Issue: Here we're making the comparison two times 
//! (One during ascending phase, another durisng descending phase)

//@ Recommended Approach
void findOccurrences2(const string& str, char ch, int i, int& first, int& last)
{
    if (i == str.size()) 
        return;

    if (str[i] == ch) {
        if (first == -1) first = i;
        last = i;              // always update last when found
    }

    findOccurrences2(str, ch, i + 1, first, last);
}

int main()
{
    string str = "baacaoga";
    char ch = 'a';
    int first = -1, last = -1;
    findOccurrences(str, ch, 0, first, last);
    cout << "First Occurrence at: " << first << endl << "Last Occurrence at: " << last;
}