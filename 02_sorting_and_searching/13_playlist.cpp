#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int n;
    cin >> n;

    vector<int> k(n);
    for (int &i: k) {
        cin >> i;
    }

    int l = 0, r = 0;
    int ans = 0;
    map<int, int> mp;

    while (r < n) {
        if (mp.find(k[r]) != mp.end() && mp[k[r]] >= l) {
            l = mp[k[r]] + 1;
        }

        mp[k[r]] = r;
        ans = max(ans, r - l + 1);
        r++;
    }

    cout << ans << "\n";

    return 0;
}