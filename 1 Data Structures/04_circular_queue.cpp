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
    if ((que.rear + 1) % que.size == que.front)
    {
        cout << "Queue is Full";
        return;
    }

    if (que.rear == -1)     // Queue was empty
        que.rear = que.front = 0;
    else
        que.rear = (que.rear + 1) % que.size;
    
    que.arr[que.rear] = num;
}

void dequeue(Queue &que)
{
    if (que.front == -1)
    {
        cout << "Queue is Empty";
        return;
    }
    if (que.front == que.rear)  // Only one element exists in Queue
        que.front = que.rear = -1;
    else
        que.front = (que.front + 1) % que.size;
}

void display(Queue &que)
{
    if (que.front == -1) {
        cout << "Queue is Empty";
        return;
    }

    int i = que.front;
    while (true)
    {
        cout << que.arr[i] << " ";
        if (i == que.rear) break;
        i = (i + 1) % que.size;
    }
}

int main()
{
    Queue que;
    que.size = 5;
    que.front = que.rear = -1;
    que.arr = new int[que.size];

    enqueue(que, 6);
    enqueue(que, 8);
    enqueue(que, 12);
    enqueue(que, 7);
    enqueue(que, 15);
    dequeue(que);
    dequeue(que);
    enqueue(que, 25);
    enqueue(que, 2);    

    display(que);
}