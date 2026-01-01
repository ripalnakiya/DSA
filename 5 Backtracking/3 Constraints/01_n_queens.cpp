/*
$ LeetCode: 51. N-Queens

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.
You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement,
where 'Q' and '.' both indicate a queen and an empty space, respectively.

$ Example 1:
# Input: n = 4
# Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

$ Example 2:
# Input: n = 1
# Output: [["Q"]]
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, vector<string> &grid, int n)
{
    // Check if no Q is present in given ___

    // 0) row is already safe since we place exactly one Q per row via backtracking and for loop in solve()

    // 1) column
    for (int i = row - 1, j = col; i >= 0; i--)
        if (grid[i][j] == 'Q')
            return false;

    // 2) diag ↗ i.e. Upper Right Diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (grid[i][j] == 'Q')
            return false;

    // 3) diag ↖ i.e. Upper Left Diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (grid[i][j] == 'Q')
            return false;

    return true;
}

void solve(int row, vector<string> &grid, vector<vector<string>> &result, int n)
{
    if (row == n)
    {
        result.push_back(grid);
        return;
    }

    // Check each position in the given row
    for (int col = 0; col < n; col++)
    {
        if (isValid(row, col, grid, n))
        {
            grid[row][col] = 'Q';
            solve(row + 1, grid, result, n);
            grid[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> result;
    vector<string> grid(n, string(n, '.')); // Fill dots in each string as per number of n
    int row = 0;
    solve(row, grid, result, n);
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