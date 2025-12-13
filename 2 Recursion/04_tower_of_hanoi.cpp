#include <iostream>
using namespace std;

// Move n discs from 'source' to 'destination' using 'helper'
void towerOfHanoi(int n, char source, char helper, char destination)
{
    // Base case: only one disc — just move it
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " -> " << destination << endl;
        return;
    }

    // Step 1: Move top n-1 discs from source to helper
    towerOfHanoi(n - 1, source, destination, helper);

    // Step 2: Move the biggest disc to destination
    cout << "Move disk " << n << " from " << source << " -> " << destination << endl;

    // Step 3: Move the n-1 discs from helper to destination
    towerOfHanoi(n - 1, helper, source, destination);
}

int main()
{
    int n = 3;
    towerOfHanoi(n, 'A', 'B', 'C');
}