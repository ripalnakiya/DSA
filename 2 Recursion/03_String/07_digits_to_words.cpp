#include <bits/stdc++.h>
using namespace std;

string getWords(int num, string *table)
{
    if (num < 10)
        return table[num];
    
    int digit = num % 10;

    return getWords(num / 10, table) + " " + table[digit];
}

int main()
{
    int num = 90;
    string table[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cout << getWords(num, table);
}