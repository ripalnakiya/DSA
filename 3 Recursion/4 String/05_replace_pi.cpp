#include <bits/stdc++.h>
using namespace std;

string replace(string str, int i = 0)
{
    if (i == str.size())
        return "";
    
    if (i + 1 < str.size() && str[i] == 'p' && str[i+1] == 'i')
    {
        return "3.14" + replace(str, i + 2);
    }
    return str[i] + replace(str, i + 1);
}

int main()
{
    string str = "pi";
    cout << replace(str) << endl;
}