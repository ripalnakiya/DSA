#include <iostream>
using namespace std;

//$ Euclidean Algorithm

//@ Iterative Approach
int getGCDi(int a, int b)
{
    while (b != 0)
    {
        int result = a % b;
        a = b;
        b = result;
    }
    return a;
}

//@ Recursive Approach
int getGCD(int a, int b)
{
    if (b == 0)
        return a;
    
    return getGCD(b, a % b);
}

int main()
{   // Make sure to keep a > b (otherwise we'll have add conditions for minimum value in the recursive function)
    int a = 25, b = 20;
    cout << getGCDi(a, b) << endl;
    cout << getGCD(a, b) << endl;
}