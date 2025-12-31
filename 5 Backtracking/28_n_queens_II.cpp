#include <bits/stdc++.h>
using namespace std;

void solve(int row, vector<int> &columnHash, vector<int> &upperRightHash, vector<int> &upperLeftHash, int &count, int n)
{
    if (row == n)
    {
        count++;
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (columnHash[col] == 0 && upperRightHash[row + col] == 0 && upperLeftHash[n - 1 + col - row] == 0)
        {
            columnHash[col] = 1;
            upperRightHash[row + col] = 1;
            upperLeftHash[n - 1 + col - row] = 1;

            solve(row + 1, columnHash, upperRightHash, upperLeftHash, count, n);

            columnHash[col] = 0;
            upperRightHash[row + col] = 0;
            upperLeftHash[n - 1 + col - row] = 0;
        }
    }
}

int totalNQueens(int n)
{
    int count = 0;
    vector<int> columnHash(n, 0);
    vector<int> upperRightHash(2 * n, 0);
    vector<int> lowerLeftHash(2 * n, 0);
    solve(0, columnHash, upperRightHash, lowerLeftHash, count, n);
    return count;
}

int main()
{
    int n = 4;
    int result = totalNQueens(n);

    cout << result << endl;
}