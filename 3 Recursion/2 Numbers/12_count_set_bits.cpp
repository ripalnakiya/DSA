#include <iostream>
using namespace std;

//! Iterative
int countSetBitsI(int num) {
    int count = 0;
    while (num) {
        // if (num & 1) ++count;        //~ Not preferred
        count = count + (num & 1);      //~ This is better
        num = num >> 1;
    }
    return count;
}

//! Recursive
int countSetBits(int num)
{
    if (num == 0)
        return 0;

    /*
    $ Check if last bit is 1
    10 →    1010
    1 →     0001
    ------------
    & →     0000 = 0   → last bit is 0 (even number)
    */    
    if ((num & 1) == 1)
        return 1 + countSetBits(num >> 1);
    else
        return countSetBits(num >> 1);
}

/*
$ Recursive/iterative bit-scan: 
~ O(k) time where k = number of bits (≈32 or 64)
~ O(k) stack depth for recursion
*/

/*
$ Kernighan’s Algorithm
n      =  1001000   (binary)
n - 1  =  1000111
-----------------
n&(n-1)=  1000000   → lowest 1 removed

# Let's try with an example: 18 (10010)
! Step1:
n      = 10010
n - 1  = 10001
& ----------------
         10000
~ count = 1

! Step2:
n      = 10000
n - 1  = 01111
& ----------------
         00000
~ count = 2

@ Loop ends → count = 2
*/
int countSetBitsK(int num) {
    int count = 0;
    while (num != 0) {
        num = num & (num - 1);  // drops the lowest set bit
        count++;
    }
    return count;
}
/*
Repeatedly clears the lowest 1-bit using n = n & (n - 1).
Runs only as many times as set bits.
Elegant, fast, and works for all unsigned integers.

!NOTE: It is fast when there are sparse 1s

# O(m) time where m = number of set bits (often faster when few 1s)
# O(1) space
*/

int main()
{
    int num = 15; // 1111 b
    cout << countSetBitsI(num) << endl;
    cout << countSetBits(num) << endl;
    cout << countSetBitsK(num) << endl;
}