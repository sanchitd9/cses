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
 
    ll sum = 0;
    for (int i = 1; i < n; i++) {
        if (x[i - 1] > x[i]) {
            sum += abs(x[i] - x[i - 1]);
            x[i] = x[i - 1];
        }
    }
 
    cout << sum << "\n";
 
    return 0;
}