#include <iostream>
using namespace std;

void recursiveFunction(int num)
{
    if (num > 0)
    {
        num = num - 2; //$ Ascending Phase
        recursiveFunction(num);
        cout << num << " "; //$ Descending Phase
    }
}

int main()
{
    recursiveFunction(7);
}