#include <bits/stdc++.h>
using namespace std;

// Function Declaration
void sort(vector<int> &v);
void insert(vector<int> &v, int num);

void sort(vector<int> &v)
{
    if (v.size() == 1)
        return;

    int last = v.back();
    v.pop_back();
    sort(v);
    insert(v, last);
}

// # Inserting in a sorted array
// # It basically builds a sorted array, by getting element one by one from sort()
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
//@ This can also be done iteratively
//@ but at this stage, it feels like recursive method is wayy to good than iterative
//@ Coz, we'll have to swap all elements to the right for inserting in middle - Here it's done seamlessly XD

int main()
{
    vector<int> v = {1, 5, 0, 2};

    sort(v);

    for (int n : v)
        cout << n << " ";
}