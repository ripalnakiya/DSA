/*
$ LeetCode: 60. Permutation Sequence

The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

$ Example 1:
# Input: n = 3, k = 3
# Output: "213"
*/

/*
$ My Note:

Given: We can't use brute force approach

We can use math to find number present at each position in the permutation. Take Example,
n = 4, k = 6          -> 1432
n = 4, k = 7          -> 2134
n = 4, k = 12         -> 2341
n = 4, k = 17         -> 3412
n = 4, k = 22         -> 4231
*/

#include <bits/stdc++.h>
using namespace std;

string solve(int lotSize, int n, int k, vector<int> &numbers)
{   
    if (n == 1)
    {
        return to_string(numbers[0]);
    }

    /* We use (k-1) for edge cases (e.g. first and last element of a lot)
     *
     * We know, index is 0-based, and k is 1-based
     *
     * Say, k = 12 and lotSize = 6
     * So we'll want 2nd element present at index [1]
     * But, (k / n) will give index = 2, and we'll get index[2] i.e. 3rd element
     */
    int index = (k - 1) / lotSize;
    // k lies on (index + 1)th lotSize

    string currentNumber = to_string(numbers[index]);
    numbers.erase(numbers.begin() + index);

    // Reduce the input size i.e. we have found the nth element so going for (n-1)th element
    n--;

    // Calculate new lot size
    int newLotSize = lotSize / n;

    // Calculate new relative kth position

    /* Say, k = 7, lotSize = 6
     * We want newKthPosition = 1
     * But (k % lotSize) will give newKthPosition = 1       -> Right
     *
     * Say, k = 12, lotSize = 6
     * We want newKthPosition = 6
     * But (k % lotSize) will give newKthPosition = 0;      -> Wrong
     */
    int newKthPosition = ((k - 1) % lotSize) + 1;

    return currentNumber + solve(newLotSize, n, newKthPosition, numbers);
}

string getPermutation(int n, int k)
{
    vector<int> numbers(n);
    int factorialN = 1;     // Factorial of N numbers
    for (int i = 0; i < n; i++)
    {
        numbers[i] = i + 1;
        factorialN = factorialN * (i + 1);
    }
    int firstLot = factorialN / n;
    return solve(firstLot, n, k, numbers);
}

int main()
{
    int n = 4, k = 7;
    string result = getPermutation(n, k);
    cout << result << endl;
}