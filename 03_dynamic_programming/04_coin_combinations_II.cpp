#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int &c: coins) {
        cin >> c;
    }

    vector<ll> dp(x + 1);
    dp[0] = 1;

    for (int c: coins) {
        for (int i = c; i <= x; i++) {
            dp[i] += dp[i - c];
            dp[i] %= MOD;
        }
    }

    cout << dp[x] << "\n";

    return 0;
}