#include <bits/stdc++.h>
#define MOD 1000000007
 
using namespace std;
using ll = long long;
 
int main() {
    ll n;
    cin >> n;
 
    ll x = 1LL;
 
    while (n > 0) {
        x = (x * 2) % MOD;
        n--;
    }
 
    cout << x % MOD << "\n";
 
    return 0;
}