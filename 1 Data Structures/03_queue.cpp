#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

void enqueue(Queue &que, int num)
{
    if (que.rear == que.size - 1)
    {
        cout << "Queue is Full";
        return;
    }

    if (que.rear == -1 && que.front == -1)
        que.rear = que.front = 0;
    else
        que.rear++;

    que.arr[que.rear] = num;
}

void dequeue(Queue &que)
{
    if (que.front == -1 && que.rear == -1)
    {
        cout << "Queue is empty";
        return;
    }

    if (que.front == que.rear)
        que.front = que.rear = -1;
    else
        que.front++;
}

void display(Queue &que)
{
    for (int i = que.front; i <= que.rear; i++)
        cout << que.arr[i] << " ";
}

int main()
{
    Queue que;
    que.size = 5;
    que.front = -1;
    que.rear = -1;
    que.arr = new int[que.size];

    enqueue(que, 6);
    enqueue(que, 8);
    enqueue(que, 12);
    enqueue(que, 7);
    enqueue(que, 15);

    dequeue(que);
    
    display(que);
}