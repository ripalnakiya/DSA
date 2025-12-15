#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &v, int num)
{
    if (v.empty() || v.back() <= num)
    {
        v.push_back(num);
        return;
    }
    int temp = v.back();
    v.pop_back();
    insert(v, num);
    v.push_back(temp);
}
//$ This is same as creating an sorted array

int main()
{
    vector<int> v = {1, 3, 4};
    int num = 2;

    insert(v, num);

    for (int n : v)
        cout << n << " ";
}