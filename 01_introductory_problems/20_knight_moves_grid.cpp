#include <bits/stdc++.h>

using namespace std;
using Grid = vector<vector<int>>;

vector<pair<int, int>> directions = {
    {1, 2}, {-1, 2}, {1, -2}, {-1, -2},
    {2, 1}, {-2, 1}, {2, -1}, {-2, -1}
};

int main() {
    int n;
    cin >> n;

    Grid grid(n, vector<int>(n, 0));
    Grid visited(n, vector<int>(n, false));

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto dir: directions) {
            int new_x = x + dir.first;
            int new_y = y + dir.second;

            if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n || visited[new_x][new_y]) {
                continue;
            }

            grid[new_x][new_y] = grid[x][y] + 1;
            visited[new_x][new_y] = true;
            q.push({new_x, new_y});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}