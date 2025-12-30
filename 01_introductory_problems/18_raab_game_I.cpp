#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
 
        if ((a + b > n) || ((a == 0 || b == 0) && !(a == 0 && b == 0))) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) cout << i << " ";
            cout << "\n";
            
            vector<bool> bitset(n, true);
            for (int i = a + 1; i <= a + b; i++) {
                cout << i << " ";
                bitset[i - 1] = false;
            }
 
            for (int i = 0; i < n; i++) {
                if (bitset[i]) {
                    cout << i + 1 << " ";
                }
            }
            cout << "\n";
        }
    }
 
    return 0;
}