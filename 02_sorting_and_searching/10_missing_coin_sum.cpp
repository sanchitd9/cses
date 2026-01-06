#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int n;
    cin >> n;

    vector<ll> x(n);
    for (ll &i: x) {
        cin >> i;
    }

    sort(x.begin(), x.end());
    ll ans = 0;

    int i = 0;
    for (; i < n; i++) {
        if (x[i] > ans + 1) {
            ans++;
            break;
        } else {
            ans += x[i];
        }
    }

    cout << (i == n ? ans + 1 : ans) << "\n";
 
    return 0;
}