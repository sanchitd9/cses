#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        ll y, x;
        cin >> y >> x;
 
        if (y >= x) {
            if (y % 2 == 0) {
                cout << y * y - x + 1;
            } else {
                cout << (y - 1) * (y - 1) + x;
            }
        } else {
            if (x % 2 != 0) {
                cout << x * x - y + 1;
            } else {
                cout << (x - 1) * (x - 1) + y;
            }
        }
        cout << "\n";
    }
 
    return 0;
}