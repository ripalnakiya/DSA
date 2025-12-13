#include <iostream>
using namespace std;

//$ Pointer Recusion
//# Where recursion processes from left, but you check from right while unwinding (returning)
//~ (This method does not use builing a reverse of a number.)

/*
   Logic:
   - Recursively go to the LEFTMOST digit.
   - While recursion UNWINDS, compare with RIGHTMOST digit.
   - We maintain `rightPart` which keeps shrinking from the right side.
*/
bool checkRec(int leftPart, int &rightPart) {

    //! Base case: if leftPart becomes 0, we've checked all digits
    if (leftPart == 0)
        return true;

    //! Go deeper towards the leftmost digit first
    if (!checkRec(leftPart / 10, rightPart))
        return false;  // Stop early if mismatch found

    //@ Compare current leftmost digit (during unwind)
    //@ with current rightmost digit (tracked by rightPart)
    int leftDigit  = leftPart % 10;
    int rightDigit = rightPart % 10;

    if (leftDigit != rightDigit)
        return false;

    //@ Move rightPart one digit inwards (drop last digit)
    rightPart /= 10;

    return true;
}

bool isPalindrome(int n) {
    if (n < 0) return false;

    int right = n;  // copy used to track right side shrinking
    return checkRec(n, right);
}

int main() {
    int n = 1221;
    cout << (isPalindrome(n) ? "Palindrome" : "Not Palindrome");
}