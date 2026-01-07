#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> get_digits(int n) {
    vector<int> result;
    while (n != 0) {
        result.push_back(n % 10);
        n /= 10;
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<ll> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        vector<int> digits = get_digits(i);
        for (int d: digits) {
            if (i - d >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - d]);
            }
        }
    }

    cout << dp[n] << "\n";

    return 0;
}