#include <bits/stdc++.h>
using namespace std;

int josephus(vector<int> &soldiers, int k, int index)
{
    if (soldiers.size() == 1)
        return soldiers[0];

    index = (index + k) % soldiers.size();
    soldiers.erase(soldiers.begin() + index);
    return josephus(soldiers, k, index);
}

int main()
{
    int n = 5;
    int k = 2;

    vector<int> soldiers(n);
    for (int i = 0; i < n; i++)
        soldiers[i] = i + 1;

    cout << josephus(soldiers, k - 1, 0);
}