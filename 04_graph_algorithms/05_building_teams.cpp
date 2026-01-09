#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>> &adj, int u, int team, vector<int> &teams) {
    if (teams[u] != -1) {
        return teams[u] == team;
    }

    teams[u] = team;
    for (int v: adj[u]) {
        if (!dfs(adj, v, 3 - team, teams)) {
            return false;
        }
    }

    return true;
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

    vector<int> teams(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (teams[i] != -1) continue;
        if (!dfs(adj, i, 1, teams)) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << teams[i] << " ";
    }
    cout << "\n";

    return 0;
}