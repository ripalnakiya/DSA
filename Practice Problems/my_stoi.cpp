#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    string s;
    cout << "Enter the number: " << endl;
    cin >> s;
    for (int i = 0; s[i] != '\0'; i++)
        num = (num * 10) + (s[i] - '0');
    cout << endl
         << "Number is " << num << endl;
    return 0;
}