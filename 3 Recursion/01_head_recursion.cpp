#include <iostream>
using namespace std;

//# When a function call is the first statement in a recursive function
//# It is called Head Recursion

void headRecursion(int num)
{
    if (num != 0) 
    {
        headRecursion(num - 1);
        cout << num << " ";
    }
}

int main()
{
    headRecursion(5);
}