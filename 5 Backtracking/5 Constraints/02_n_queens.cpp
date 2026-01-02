#include <bits/stdc++.h>
using namespace std;

/*
This is a optimized version which uses hashing to find the valid position of a Queen in O(1),
Whereas, in previous solution, time complexity to find valid position of a Queen was O(3 * n)
*/

void solve(int row, vector<string> &grid, vector<int> &columnHash, vector<int> &upperRightHash, vector<int> &upperLeftHash, vector<vector<string>> &result, int n)
{
    if (row == n)
    {
        result.push_back(grid);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (columnHash[col] == 0 && upperRightHash[row + col] == 0 && upperLeftHash[n - 1 + col - row] == 0)
        {

            grid[row][col] = 'Q';
            columnHash[col] = 1;
            upperRightHash[row + col] = 1;
            upperLeftHash[n - 1 + col - row] = 1;

            solve(row + 1, grid, columnHash, upperRightHash, upperLeftHash, result, n);

            grid[row][col] = '.';
            columnHash[col] = 0;
            upperRightHash[row + col] = 0;
            upperLeftHash[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> result;
    vector<string> grid(n, string(n, '.'));
    vector<int> columnHash(n, 0);
    vector<int> upperRightHash(n * 2, 0);
    vector<int> upperLeftHash(n * 2, 0);
    solve(0, grid, columnHash, upperRightHash, upperLeftHash, result, n);
    return result;
}

int main()
{
    int n = 4;
    vector<vector<string>> result = solveNQueens(n);

    for (auto &i : result)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}