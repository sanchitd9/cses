#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<int> x(n);
    map<int, int> mp;
    for (int &i: x) {
        cin >> i;
        mp[i]++;
    }

    ll ans = 1;
    for (auto it: mp) {
        ans = (ans * (it.second + 1)) % MOD;
    }

    cout << (ans - 1) % MOD << "\n";

    return 0;
}