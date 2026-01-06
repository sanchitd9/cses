#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<int> x(n);
    for (int &i: x) {
        cin >> i;
    }

    map<int, int> mp;
    int l = 0;
    ll ans = 0;
    for (int r = 0; r < n; r++) {
        if (mp.find(x[r]) !=  mp.end() && mp[x[r]] >= l) {
            l = mp[x[r]] + 1;
        }

        mp[x[r]] = r;
        ans += r - l + 1;
    }

    cout << ans << "\n";

    return 0;
}