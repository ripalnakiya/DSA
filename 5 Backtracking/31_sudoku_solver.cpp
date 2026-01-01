/*
$ LeetCode: 37. Sudoku Solver
*/

#include <bits/stdc++.h>
using namespace std;

/*  We can take reference from "Valid Sudoku" solutio to improve this function   */
bool isValid(char num, int row, int col, vector<vector<char>> &board)
{
    // Check if number already exists in given row
    for (int j = 0; j < 9; j++)
        if (board[row][j] == num)
            return false;

    // Check if number already exists in given column
    for (int i = 0; i < 9; i++)
        if (board[i][col] == num)
            return false;

    // Check if number already exists in given sub-square
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (board[i][j] == num)
                return false;
        }
    }

    return true;
}

bool solve(vector<vector<char>> &board)
{
    // Traverse the board to find the first empty cell
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            // If an empty cell is found, we must fill it
            if (board[i][j] == '.')
            {
                // Try placing digits 1 to 9 in the empty cell
                for (char num = '1'; num <= '9'; num++)
                {

                    // Check whether placing this digit is valid according to Sudoku rules (row, column, sub-grid)
                    if (isValid(num, i, j, board))
                    {
                        board[i][j] = num;

                        // Recursively attempt to solve the rest of the board If this leads to a solution, propagate success upward
                        if (solve(board))
                            return true;

                        // If placing this digit leads to a dead end, undo the choice (backtrack) and try the next digit
                        board[i][j] = '.';
                    }
                }
                // If no digit from 1 to 9 can be placed in this cell, the current board configuration is invalid.
                // Signal failure so previous recursive calls can backtrack.
                return false;
                // If any of the number were valid, then recursion would have moved ahead, to the next call, and we would never reach here
                // But since we reached here, none of the value is valid for given position, and hence backtrack
            }
        }
    }
    // If no empty cells remain, the board is completely filled and all Sudoku constraints are satisfied.
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    /*
     * Sudoku is solved using cell-based backtracking.
     * At each recursive step, we scan the board to find the next empty cell
     * and try placing digits 1 to 9 that satisfy Sudoku constraints.
     *
     * Unlike problems such as N-Queens, we do not backtrack row by row.
     * The next position to process is determined dynamically by locating
     * the next empty cell ('.') in the board.
     *
     * There is no need to pass row or column indices as parameters.
     * The board is passed by reference, so each recursive call works on
     * the updated board state and naturally progresses toward a solution.
     */
    solve(board);
}

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSudoku(board);

    for (auto &i : board)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}