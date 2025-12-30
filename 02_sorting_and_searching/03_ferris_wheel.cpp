#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int n;
    ll x;
    cin >> n >> x;
 
    vector<ll> p(n);
    for (ll &i: p) {
        cin >> i;
    }
 
    sort(p.begin(), p.end());
    int l = 0, r = n - 1;
    int count = 0;
 
    while (l < r) {
        if (p[l] + p[r] > x) {
            r--;
        } else {
            l++;
            r--;
        }
        count++;
    }
 
    if (l == r) count++;
 
    cout << count << "\n";
 
    return 0;
}