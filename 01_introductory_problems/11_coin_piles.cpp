#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        int a, b;
        cin >> a >> b;
        ll sum = (ll) a + b;
 
        if (a == 0 && b == 0) {
            cout << "YES\n";
            continue;
        }
 
        if (a == 0 || b == 0) {
            cout << "NO\n";
            continue;
        }
 
        if (sum % 3 != 0) {
            cout << "NO\n";
        } else {
            if (a < b) swap(a, b);
            if (a / (double) b > 2) cout << "NO\n";
            else cout << "YES\n";
        }
    }
 
    return 0;
}