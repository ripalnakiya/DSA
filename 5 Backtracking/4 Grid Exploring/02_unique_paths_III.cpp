/*
$ LeetCode: 980. Unique Paths III

You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending square,
that walk over every non-obstacle square exactly once.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> xAxis = {1, 0, 0, -1};
vector<int> yAxis = {0, -1, 1, 0};

bool isValid(int x, int y, vector<vector<int>> &grid, int m, int n)
{
    return (x >= 0 && y >= 0 && x < m && y < n) && (grid[x][y] != -1 && grid[x][y] != -9);
}

void findPath(int x, int y, int &count, vector<vector<int>> &grid, int m, int n, int remainingSquares)
{
    if (grid[x][y] == 2)
    {
        if (remainingSquares == 1)
            count++;
        return;
    }

    int temp = grid[x][y];
    grid[x][y] = -9; // mark visited (distinct marker)

    for (int i = 0; i < 4; i++)
    {
        int newX = x + xAxis[i];
        int newY = y + yAxis[i];
        if (isValid(newX, newY, grid, m, n))
        {
            findPath(newX, newY, count, grid, m, n, remainingSquares - 1);
        }
    }

    grid[x][y] = temp; // backtrack
}

int uniquePathsIII(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    // Since we want to cover all the squares
    int remaining = 0;
    int startX = 0, startY = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] != -1)
            {
                remaining++;
            }
            if (grid[i][j] == 1)
            {
                startX = i;
                startY = j;
            }
        }
    }

    int count = 0;
    findPath(startX, startY, count, grid, m, n, remaining);
    return count;
}

int main() {
    vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
    int result = uniquePathsIII(grid);

    cout << result << endl;
}