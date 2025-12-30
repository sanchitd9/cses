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
 
    ll sum = 0;
    ll ans = INT_MIN;
 
    for (ll i: x) {
        sum = max(i, sum + i);
        ans = max(ans, sum);
    }
 
    cout << ans << "\n";
 
    return 0;
}