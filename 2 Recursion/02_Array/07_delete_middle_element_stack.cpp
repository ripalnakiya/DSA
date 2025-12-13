#include <bits/stdc++.h>
using namespace std;

void deleteMid(stack<int> &s, int k)
{
    if (k == 1)
    {
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    deleteMid(s, k - 1);
    s.push(temp);
}

int main()
{
    stack<int> s;
    for (int x : {1, 2, 3, 4, 5})
        s.push(x);

    int mid = s.size() / 2 + 1;

    deleteMid(s, mid);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}