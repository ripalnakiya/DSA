/*
Leetcode: 1324
$ Given an integer num, return the number of steps to reduce it to zero.
$ In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.
*/

/*
# Input: num = 14
# Output: 6
! Explanation: 
Step 1) 14 is even; divide by 2 and obtain 7. 
Step 2) 7 is odd; subtract 1 and obtain 6.
Step 3) 6 is even; divide by 2 and obtain 3. 
Step 4) 3 is odd; subtract 1 and obtain 2. 
Step 5) 2 is even; divide by 2 and obtain 1. 
Step 6) 1 is odd; subtract 1 and obtain 0.
*/

/*
# Input: num = 8
# Output: 4
! Explanation: 
Step 1) 8 is even; divide by 2 and obtain 4. 
Step 2) 4 is even; divide by 2 and obtain 2. 
Step 3) 2 is even; divide by 2 and obtain 1. 
Step 4) 1 is odd; subtract 1 and obtain 0.
*/

#include<iostream>
using namespace std;

//@ My first approach
int countSteps(int num, int steps)
{
    if (num == 0)
        return steps;
    
    if (num % 2 == 0)
        return countSteps(num / 2, steps + 1);
    
    return countSteps(num - 1, steps + 1);
}

//@ My second approach
int countSteps2(int num)
{
    if (num == 0)
        return 0;
    
    if (num % 2 == 0)
        return 1 + countSteps2(num / 2);
    
    return 1 + countSteps2(num - 1);
}
//~ This one is better approach

int main()
{
    int num = 14;
    cout << countSteps(14, 0) << endl;
    cout << countSteps2(14);
}