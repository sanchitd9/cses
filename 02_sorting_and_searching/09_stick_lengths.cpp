#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int n;
    cin >> n;
 
    vector<ll> p(n);
 
    for (ll &i: p) {
        cin >> i;
    }
 
    sort(p.begin(), p.end());
    ll median = p[n / 2];
 
    ll ans = 0;
    for (ll x: p) {
        ans += abs(x - median);
    }
 
    cout << ans << "\n";
 
    return 0;
}