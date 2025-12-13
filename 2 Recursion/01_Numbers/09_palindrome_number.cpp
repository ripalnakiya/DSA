#include <iostream>
using namespace std;

//$ Recursive function
bool isPalindromeRec(int n, int divisor) 
{
    // Base case: reached center
    if (n < 10) return true;

    int first = n / divisor;     // most significant digit
    int last  = n % 10;          // least significant digit

    if (first != last) return false;

    // Remove first and last digits
    n = (n % divisor) / 10;

    // Reduce divisor by 2 digits
    divisor /= 100;

    return isPalindromeRec(n, divisor);
}

//$ Helper function
bool isPalindrome(int n) 
{
    if (n < 0) return false;   // negative numbers aren't palindromes

    int divisor = 1;
    // Set divisor to highest power of 10 <= n
    while (n / divisor >= 10) divisor *= 10;

    return isPalindromeRec(n, divisor);
}

int main() 
{
    int n = 1221;
    if (isPalindrome(n)) cout << "Palindrome";
    else cout << "Not Palindrome";
}