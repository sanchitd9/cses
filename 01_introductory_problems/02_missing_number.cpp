#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int n;
    cin >> n;
 
    vector<int> arr(n - 1);
    ll sum = 0;
    for (int &x: arr) {
        cin >> x;
        sum += x;
    }
 
    cout << ((ll)n * (n + 1)) / 2 - sum << "\n";
    
    return 0;
}