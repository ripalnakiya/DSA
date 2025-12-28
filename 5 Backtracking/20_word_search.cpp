/*
$ LeetCode: 79. Word Search

Execution Time: 250+ ms
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> xAxis = {1, 0, 0, -1};
vector<int> yAxis = {0, -1, 1, 0};

bool confirmSequence(int x, int y, int index, vector<vector<char>>& board, string &word) {
    if (index == word.length())
        return true;

    // Mark the current element as visited
    char original = board[x][y];
    board[x][y] = '#';

    for (int i = 0; i < 4; i++) {
        int newX = x + xAxis[i];
        int newY = y + yAxis[i];
        if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size() && board[newX][newY] == word[index]) {
            if (confirmSequence(newX, newY, index + 1, board, word))
                return true;
        }
    }

    // Backtrack
    board[x][y] = original;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {

    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[0]) {
                if (confirmSequence(i, j, 1, board, word))
                    return true;
            }
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCB";
    bool result = exist(board, word);

    cout << result << endl;
}