/*
$ LeetCode: 1052. Grumpy Bookstore Owner

There is a bookstore owner that has a store open for n minutes.
You are given an integer array customers of length n
where customers[i] is the number of the customers
that enter the store at the start of the ith minute and all those customers leave after the end of that minute.

During certain minutes, the bookstore owner is grumpy.
You are given a binary array grumpy
where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.

When the bookstore owner is grumpy,
the customers entering during that minute are not satisfied. Otherwise, they are satisfied.

The bookstore owner knows a secret technique to remain not grumpy for minutes consecutive minutes,
but this technique can only be used once.

Return the maximum number of customers that can be satisfied throughout the day.

$ Example 1:
# Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
# Output: 16
Explanation:
The bookstore owner keeps themselves not grumpy for the last 3 minutes.
The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.

$ Example 2:
# Input: customers = [1], grumpy = [0], minutes = 1
# Output: 1
*/

#include <bits/stdc++.h>
using namespace std;

int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
{
    int maxSatisfied = 0;

    // These customers are satisfied no matter what
    for (int i = 0; i < customers.size(); i++)
        if (grumpy[i] == 0)
            maxSatisfied += customers[i];

    // Sliding window over only grumpy minutes
    int window = 0;
    for (int i = 0; i < minutes; i++)
        if (grumpy[i] == 1)
            window += customers[i];

    int windowMax = window;

    // How many extra customers can I convert to satisfied if I use the secret technique here?
    for (int i = minutes; i < grumpy.size(); i++)
    {
        if (grumpy[i] == 1)
            window += customers[i];
        if (grumpy[i - minutes] == 1)
            window -= customers[i - minutes];

        windowMax = max(window, windowMax);
    }
    return maxSatisfied + windowMax;
}

int main()
{
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;

    int result = maxSatisfied(customers, grumpy, minutes);

    cout << result;
}