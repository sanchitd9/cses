#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adj, int start, vector<bool> &visited) {
    if (visited[start]) {
        return;
    }

    visited[start] = true;

    for (int u: adj[start]) {
        dfs(adj, u, visited);
    }
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

    vector<int> ans;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ans.push_back(i);
            dfs(adj, i, visited);
        }
    }

    cout << (int) ans.size() - 1 << "\n";
    for (int i = 0; i < (int) ans.size() - 1; i++) {
        cout << ans[i] << " " << ans[i + 1] << "\n";
    }

    return 0;
}