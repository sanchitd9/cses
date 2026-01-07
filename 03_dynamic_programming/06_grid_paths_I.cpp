#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*') {
        cout << 0 << "\n";
        return 0;
    }

    vector<vector<ll>> dp(n, vector<ll>(n));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i - 1 >= 0 && j - 1 >= 0) {
                if (grid[i - 1][j] == '.') {
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= MOD;
                } 

                if (grid[i][j - 1] == '.') {
                    dp[i][j] += dp[i][j - 1];
                    dp[i][j] %= MOD;
                }

                continue;
            }
            
            if (i - 1 >= 0) {
                if (grid[i - 1][j] == '.') {
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= MOD;
                }

                continue;
            } 
            
            if (j - 1 >= 0) {
                if (grid[i][j - 1] == '.') {
                    dp[i][j] += dp[i][j - 1];
                    dp[i][j] %= MOD;
                }
                
                continue;
            }
        }
    }

    cout << dp[n - 1][n - 1] << "\n";

    return 0;
}