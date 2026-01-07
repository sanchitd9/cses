#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> h(n), s(n);
    for (int &i: h) cin >> i;
    for (int &i: s) cin >> i;

    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = x; j >= h[i]; j--) {
            dp[j] = max(dp[j], s[i] + dp[j - h[i]]);
        }
    }

    cout << dp[x] << "\n";

    return 0;
}