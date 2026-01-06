#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll x;
    int n;
    cin >> x >> n;

    vector<ll> p(n);
    for (ll &i: p) {
        cin >> i;
    }

    multiset<ll> segments{0, x};
    multiset<ll> dist{x};

    for (int i = 0; i < n; i++) {
        segments.insert(p[i]);
        auto it = segments.find(p[i]);
        ll l = *prev(it);
        ll r = *next(it);

        dist.erase(dist.find(r - l));
        dist.insert(p[i] - l);
        dist.insert(r - p[i]);

        cout << *dist.rbegin() << " ";
    }
    cout << "\n";

    return 0;
}