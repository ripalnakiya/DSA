#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *first;

void insertAtEnd(int data)
{
    Node *n = new Node;
    n->data = data;
    n->next = NULL;

    if (first == NULL)
        first = n;
    else
    {
        Node *p = first;
        while (p->next != NULL)
            p = p->next;
        p->next = n;
    }
}

void display()
{
    Node *p = first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    insertAtEnd(5);
    insertAtEnd(8);
    insertAtEnd(12);
    display();
}