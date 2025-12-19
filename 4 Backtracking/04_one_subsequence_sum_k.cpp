#include <bits/stdc++.h>
using namespace std;

bool subsequences(int index, vector<int> &store, int &sum, vector<int> &list, int &k)
{
    if (index >= list.size())
    {
        if (sum == k)
        {
            for (int n : store)
                cout << n << " ";
            return true;
        }
        return false;
    }

    sum += list[index];
    store.push_back(list[index]);
    if(subsequences(index + 1, store, sum, list, k))
        return true;
    
    sum -= list[index];
    store.pop_back();
    if(subsequences(index + 1, store, sum, list, k))
        return true;
}

int main()
{
    vector<int> list = {1, 2, 1};
    vector<int> store;
    int sum = 0;

    int k = 2;

    subsequences(0, store, sum, list, k);
}