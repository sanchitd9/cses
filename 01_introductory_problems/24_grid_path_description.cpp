#include <bits/stdc++.h>

using namespace std;
const int n = 7;
const int len = 48;

int dfs(string &s, int x, int y, int i, vector<vector<bool>> &visited) {
    // Out of bounds / revisiting a cell
    if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y]) {
        return 0;
    }

    // If we cannot go up and down
    if (y - 1 >= 0 && y + 1 < n && !visited[x][y - 1] && !visited[x][y + 1] && ((x == 0 && visited[x + 1][y]) || (x == n - 1 && visited[x - 1][y]) || (visited[x + 1][y] && visited[x - 1][y]))) {
        return 0;
    }
 
    // If we cannot go left && right
    if (x - 1 >= 0 && x + 1 < n && !visited[x - 1][y] && !visited[x + 1][y] && ((y == 0 && visited[x][y + 1]) || (y == n - 1 && visited[x][y - 1]) || visited[x][y - 1] && visited[x][y + 1])) {
        return 0;
    }

    if (x == n - 1 && y == 0) {
        return i == len;
    }

    visited[x][y] = 1;
    int ways = 0;
    if (s[i] == '?') {
        ways += dfs(s, x + 1, y, i + 1, visited);
        ways += dfs(s, x - 1, y, i + 1, visited);
        ways += dfs(s, x, y + 1, i + 1, visited);
        ways += dfs(s, x, y - 1, i + 1, visited);
    } else if (s[i] == 'U') {
        ways += dfs(s, x - 1, y, i + 1, visited);
    } else if (s[i] == 'D') {
        ways += dfs(s, x + 1, y, i + 1, visited);
    } else if (s[i] == 'L') {
        ways += dfs(s, x, y - 1, i + 1, visited);
    } else {
        ways += dfs(s, x, y + 1, i + 1, visited);
    }

    visited[x][y] = false;

    return ways;
}

int main() {
    string s;
    cin >> s;

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    cout << dfs(s, 0, 0, 0, visited) << "\n";

    return 0;
}