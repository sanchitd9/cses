#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vector<bool> x(4, true);
            x[grid[i][j] - 'A'] = false;
            if (i - 1 >= 0) x[grid[i - 1][j] - 'A'] = false;
            if (j - 1 >= 0) x[grid[i][j - 1] - 'A'] = false;

            for (int k = 0; k < 4; k++) {
                if (x[k]) {
                    grid[i][j] = (char) (k + 'A');
                    break;
                }
            }
            cout << grid[i][j];
        }
        cout << "\n";
    }

    return 0;
}