/*
$ LeetCode: 1219. Path with Maximum Gold
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> xAxis = {1, 0, 0, -1};
vector<int> yAxis = {0, -1, 1, 0};

void solve(int x, int y, int currentGold, int &maxGold, vector<vector<int>>& grid, int m, int n) {
    maxGold = max(maxGold, currentGold);

    int original = grid[x][y];
    grid[x][y] = 0;
    
    for (int i = 0; i < 4; i++) {
        int newX = x + xAxis[i];
        int newY = y + yAxis[i];

        if (newX >= 0 && newY >= 0 && newX < m && newY < n && grid[newX][newY] != 0) {
            solve(newX, newY, currentGold + grid[newX][newY], maxGold, grid, m, n);
        }
    }

    grid[x][y] = original;
}

int getMaximumGold(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int maxGold = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != 0) {
                solve(i, j, grid[i][j], maxGold, grid, m, n);
            }
        }
    }

    return maxGold;
}

int main() {
    vector<vector<int>> grid = {
        {0, 6, 0},
        {5, 8, 7},
        {0, 9, 0}
    };
    int result = getMaximumGold(grid);
    cout << result << endl;
}