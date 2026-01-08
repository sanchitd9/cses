#include <bits/stdc++.h>

using namespace std;
using Grid = vector<vector<char>>;
using Point = pair<int, int>;

vector<Point> directions = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

bool bfs(Grid &grid, Point const &start, Point const &end, const int n, const int m, string &ans) {
    queue<Point> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<Point>> parent(n, vector<Point>(m, {-1, -1}));

    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        if (current == end) {
            Point i = end;
            while (i != start) {
                auto n = parent[i.first][i.second];
                char ch;
                if (n.first > i.first) ch = 'U';
                if (n.first < i.first) ch = 'D';
                if (n.second > i.second) ch = 'L';
                if (n.second < i.second) ch = 'R';

                ans.push_back(ch);
                i = n;
            }

            reverse(ans.begin(), ans.end());
            return true;
        }

        for (auto dir: directions) {
            int new_x = current.first + dir.first;
            int new_y = current.second + dir.second;

            if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m || visited[new_x][new_y] || grid[new_x][new_y] == '#') {
                continue;
            }
            
            q.push({new_x, new_y});
            parent[new_x][new_y] = current;
            visited[new_x][new_y] = true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    Grid grid(n, vector<char>(m));
    Point start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }

    string ans;
    if (bfs(grid, start, end, n, m, ans)) {
        cout << "YES\n";
        cout << ans.size() << "\n";
        cout << ans << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}