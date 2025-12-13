#include <bits/stdc++.h>
using namespace std;

// Function Declaration
void reverse(stack<int> &s);
void insert(stack<int> &s, int num);

void reverse(stack<int> &s)
{
    if (s.size() == 1)
        return;

    int last = s.top();
    s.pop();
    reverse(s);
    insert(s, last);
}

void insert(stack<int> &s, int num)
{
    if (s.empty()) {
        s.push(num);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s, num);
    s.push(temp);
}

int main()
{
    stack<int> s;
    for (int x : {1, 2, 3, 4, 5})   // base: 1, 2, 3, 4, 5 (top)
        s.push(x);

    reverse(s);

    while (!s.empty())
    {
        cout << s.top() << " "; // prints from top to base
        s.pop();
    }
}