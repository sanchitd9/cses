#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int q;
    cin >> q;

    while (q--) {
        ll k;
        cin >> k;

        int digits = 1;
        ll start = 1;
        ll count = 9;

        while (k > digits * count) {
            k -= digits * count;
            digits++;
            count *= 10;
            start *= 10;
        }

        ll num = start + (k - 1) / digits;
        string s = to_string(num);
        int index = (k - 1) % digits;

        cout << s[index] << "\n";
    }

    return 0;
}