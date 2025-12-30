#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
void solve(vector<ll> &p, int i, ll curr, ll &ans, ll &total) {
    if (i >= (int) p.size()) {
        ll diff = abs(curr - abs(curr - total));
        if (diff < ans) {
            ans = diff;
        }
 
        return;
    }
 
    // include
    solve(p, i + 1, curr + p[i], ans, total);
    // exclude
    solve(p, i + 1, curr, ans, total);
}
 
int main() {
    int n;
    cin >> n;
 
    vector<ll> p(n);
    ll total = 0;
    for (ll &x: p) {
        cin >> x;
        total += x;
    }
    
    ll ans = INT64_MAX;
    solve(p, 0, 0, ans, total);
 
    cout << ans << "\n";
 
    return 0;
}