#include <bits/stdc++.h>
using namespace std;

void decode(int index, string &str)
{
    if (index == str.length() - 1)
        return;

    if (str[index] >= 48 && str[index] <= 57) // It's a number
    {
        int num = str[index] - 48;

        // get the complete number;
        int i;
        for(i = index + 1; str[i] != '['; i++)
            num = (num * 10) + (str[i] - 48);

        cout << num;
        
        // decode(i + 1, str);
    }
}

int main()
{
    string str = "32[a2[c]]";
    decode(0, str);
    // cout << str;
}