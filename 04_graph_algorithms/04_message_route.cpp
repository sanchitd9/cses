#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int>> &adj, int n, vector<int> &parent) {
    queue<int> q;
    vector<bool> visited(n + 1, false);

    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int s = q.front();
        q.pop();

        for (auto u: adj[s]) {
            if (visited[u]) continue;
            visited[u] = true;
            parent[u] = s;
            q.push(u);
        }
    }

    return parent[n];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent(n + 1, -1);
    int ans = bfs(adj, n, parent);
    if (ans == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> route;
        int i = n;
        while (i != -1) {
            route.push_back(i);
            i = parent[i];
        }

        cout << route.size() << "\n";
        for (auto it = route.rbegin(); it != route.rend(); it++) {
            cout << *it << " ";
        }
        cout << "\n";
    }

    return 0;
}