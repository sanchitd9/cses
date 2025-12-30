#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int n;
    cin >> n;
 
    for (ll i = 1; i <= n; i++) {
        ll i_squared = i * i;
        cout << (i_squared * (i_squared - 1)) / 2 - 4 * (i - 1) * (i - 2) << "\n";
    }
 
    return 0;
}