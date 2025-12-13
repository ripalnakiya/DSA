#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *arr;
};

void push(Stack &st, int num)
{
    if (st.top == st.size - 1)
    {
        cout << "Stack Overflow";
        return;
    }
    st.arr[++st.top] = num;
}

int pop(Stack &st)
{
    if(st.top == -1)
    {
        cout << "Stack Underflow";
        return -1;
    }
    return st.arr[st.top--];
}

void display(Stack &st)
{
    Stack temp = st;
    while(temp.top != -1)
    {
        cout << pop(temp) << " ";
    }
}

int main()
{
    Stack st;
    st.size = 5;
    st.top = -1;
    st.arr = new int[st.size];

    push(st, 5);
    push(st, 6);
    push(st, 8);
    push(st, 8);    
    push(st, 8);    
    display(st);
}