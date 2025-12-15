#include <iostream>
using namespace std;

//# When a function call is the last statement in a recursive function
//# It is called Tail Recursion

void tailRecursion(int num)
{
    if (num != 0) 
    {
        cout << num << " ";
        tailRecursion(num - 1);
    }
}

int tailRecursion2(int num)
{
    if (num <= 0)
        return 0;
    return num + tailRecursion2(num - 1);
}
//! This is NOT tail recursion, bcz it is doing some more operations (addition)
//! after the recursion call returns.

int main()
{
    tailRecursion(5);
    cout << endl << tailRecursion2(5);
}