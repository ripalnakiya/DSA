#include <bits/stdc++.h>
using namespace std;

//$ Program to find all the subsequences with sum k
//! If we calculate the value of sum in the each leaf node, time complexity will increase by n
//! So using extra variable to have sum of all the store elements

void subsequences(int index, vector<int> &store, int &sum, vector<int> &list, int &k)
{
    if (index >= list.size())
    {
        if (sum == k)
        {
            for (int n : store)
                cout << n << " ";
            cout << endl;
        }
        return;
    }

    sum += list[index];
    store.push_back(list[index]);
    subsequences(index + 1, store, sum, list, k);
    
    sum -= list[index];
    store.pop_back();
    
    subsequences(index + 1, store, sum, list, k);
}

int main()
{
    vector<int> list = {1, 2, 1};
    vector<int> store;
    int sum = 0;

    int k = 2;

    subsequences(0, store, sum, list, k);
}