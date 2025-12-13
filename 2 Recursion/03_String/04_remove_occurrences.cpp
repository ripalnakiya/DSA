#include <bits/stdc++.h>
using namespace std;

string removeAllI(string str, char ch)
{
    string result = "";
    for (char c : str) {
        if (c != ch)
            result += c;
    }
    return result;
}

string removeAll(string str, char ch, int i = 0)
{
    if (i == str.size())
        return "";
    
    if (str[i] == ch)
        return removeAll(str, ch, i + 1);
    
    return str[i] + removeAll(str, ch, i + 1);
}

//$ Understanding this approach (though simpler than previous one)
//$ Will provide skeleton for advance recursion problems
string removeAll2(const string &s, char ch, int i = 0) {
    // Base case: reached end of string
    if (i == s.size())
        return "";

    // Recursive call for rest of string
    string smallAns = removeAll(s, ch, i + 1);

    // Decide whether to include s[i] or skip it
    if (s[i] == ch)
        return smallAns;              // skip this character
    else
        return s[i] + smallAns;       // include this character
}

int main()
{
    string str = "foobar";
    char ch = 'o';
    cout << removeAllI(str, ch) << endl;
    cout << removeAll(str, ch) << endl;
    cout << removeAll2(str, ch) << endl;
}