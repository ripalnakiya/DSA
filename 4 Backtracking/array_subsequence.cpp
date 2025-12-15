//$ Program to print all the subsequences
// Input: {3, 1, 2}
// Output: {3 1 2}, {3 1}, {3 2}, {3}, {1 2}, {1}, {2}
// Subsequences follow the sequence of elements as originally present in arary.
// Hence, {1 2 3} is not a sub sequence. 
#include <bits/stdc++.h>
using namespace std;

void printSubsequence(int index, vector<int> &store, vector<int> &arr)
{
    if (index >= arr.size())
    {
        for (int x : store)
            cout << x << " ";
        if (store.size() == 0)
            cout << "{}";
        cout << endl;
        return;
    }

    //! take the element, therefore adding it in store
    store.push_back(arr[index]);
    printSubsequence(index + 1, store, arr);
    store.pop_back();

    //! do not take the element
    printSubsequence(index + 1, store, arr);
}

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> store;

    printSubsequence(0, store, arr);
}