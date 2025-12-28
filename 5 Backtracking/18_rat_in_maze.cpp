#include <bits/stdc++.h>
using namespace std;

vector<int> xAxis = {1, 0, 0, -1};
vector<int> yAxis = {0, -1, 1, 0};
string directions = "DLRU";

bool isValid(int x, int y, vector<vector<int>> &arr, int n) {
    return x >= 0 && y >= 0 && x < n && y < n && arr[x][y] != 0;
}

void solve(int x, int y, string path, vector<string> &result, vector<vector<int>> &arr, int n) {
    if (x == n-1 && y == n-1) {
        result.push_back(path);
        return;
    }

    // Mark current cell as visited
    arr[x][y] = 0;

    for (int i = 0; i < directions.size(); i++) {
        int newX = x + xAxis[i];
        int newY = y + yAxis[i];
        if (isValid(newX, newY, arr, n)) {
            path.push_back(directions[i]);
            solve(newX, newY, path, result, arr, n);
            path.pop_back();
        }
    }

    // Unmark current cell
    arr[x][y] = 1;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    string path = "";
    vector<string> result;
    if (arr[0][0] != 0)
        solve(0, 0, path, result, arr, n);
    return result;
}

int main() {
    vector<vector<int> > arr = {{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> result = searchMaze(arr, 4);

    for (string s : result) {
        cout << s << endl;
    }
}