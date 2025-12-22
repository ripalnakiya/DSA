#include <bits/stdc++.h>
using namespace std;

void removeOccurrences(stack<int> &st, int num)
{
    if (st.empty())
        return;
    
    int temp = st.top();
    st.pop();
    removeOccurrences(st, num);
    if(temp != num)
        st.push(temp);
}

int main()
{
    stack<int> st;
    for (int x : {1, 2, 3, 2, 4, 2})   // base: 1, 2, 3, 2, 4, 2 (top)
        st.push(x);
    
    int num = 2;

    removeOccurrences(st, num);

    while (!st.empty())
    {
        cout << st.top() << " "; // prints from top to base
        st.pop();
    }    
}