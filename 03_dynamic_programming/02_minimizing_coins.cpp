#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int &c: coins) {
        cin >> c;
    }

    vector<ll> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (int c: coins) {
            if (i - c >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - c]);
            }
        }
    }

    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << "\n";

    return 0;
}