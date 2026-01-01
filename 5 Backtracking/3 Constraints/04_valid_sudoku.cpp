/*
$ LeetCode: 36. Valid Sudoku
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(char num, int row, int col, vector<vector<char>>& board) {
    int count = 0;
    for (int i = 0; i < 9; i++) {
        // Check row
        if (board[row][i] == num)   count++;

        // Check column
        if (board[i][col] == num)   count++;

        // Check sub-square
        int r = 3 * (row / 3) + (i / 3);
        int c = 3 * (col / 3) + (i % 3);
        if (board[r][c] == num) count++;

        // Each 'check' will count the same number, hence in valid condition count should be 3
        if (count > 3)
            return false;
    }
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.' && !isValid(board[i][j], i, j, board))
                return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    bool result = isValidSudoku(board);
    cout << result << endl;
}