#include <iostream>
using namespace std;

//$ Program prints the fibonacci series upto Nth element

void printFibonacci(int a, int b, int limit)
{
    if (limit == 0)
        return;

    int sum = a + b;
    cout << sum << " ";
    printFibonacci(b, sum, limit - 1);
}

void printReverseFibonacci(int a, int b, int limit)
{
    if (limit == 0)
        return;

    int sum = a + b;
    printReverseFibonacci(b, sum, limit - 1);
    cout << a << " ";
}

int main()
{
    int limit = 6;
    cout << "Forward: ";
    cout << "0 1 ";
    printFibonacci(0, 1, limit);

    cout << "\nReverse: ";
    printReverseFibonacci(0, 1, limit);
}