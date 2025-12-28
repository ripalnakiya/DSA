/*
$ LeetCode: 79. Word Search

This is more optimised, we've used two more pruning techniques here:
1.  If there are no enough chars to form a word, return False
2.  Counting 1st & last char of word in board and
    if 1st char count is greater, reverse the word before calling dfs (That way we'll have to explore less choices)

Execution Time: 0 ms
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> xAxis = {1, 0, 0, -1};
vector<int> yAxis = {0, -1, 1, 0};

bool confirmSequence(int x, int y, int index, vector<vector<char>> &board, string &word) {
    if (index == word.length())
        return true;

    // Mark the current element as visited
    char original = board[x][y];
    board[x][y] = '#';

    for (int i = 0; i < 4; i++) {
        int newX = x + xAxis[i];
        int newY = y + yAxis[i];
        if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size() && board[newX][newY] == word[
                index]) {
            if (confirmSequence(newX, newY, index + 1, board, word))
                return true;
        }
    }

    // Backtrack
    board[x][y] = original;
    return false;
}

bool exist(vector<vector<char>> &board, string word) {
    int m = board.size();
    int n = board[0].size();

    // To improve the pruning
    map<char, int> mp;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mp.find(board[i][j]) == mp.end())
                mp.insert({board[i][j], 1});
            else
                mp[board[i][j]]++;
        }
    }

    map<char, int> mpWord;
    for (char c: word) {
        if (mpWord.find(c) == mp.end())
            mpWord.insert({c, 1});
        else
            mpWord[c]++;
    }

    // Pruning 1:   If there are no enough chars to form a word, return False
    for (const auto &it: mpWord) {
        if (mp.find(it.first) == mp.end() || mp[it.first] < it.second)
            return false;
    }

    // Pruning 2:   Counting 1st & last char of word in board and
    //              if 1st char count is greater, reverse the word before calling dfs 
    //              (That way we'll have to explore less choices)

    if (mp.at(word.front()) > mp.at(word.back())) {
        for (int i = 0, j = word.length() - 1; i < j; i++, j--) {
            char c = word[i];
            word[i] = word[j];
            word[j] = c;
        }
    }

    // Perform the search
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