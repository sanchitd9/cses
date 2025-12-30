#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int n;
    cin >> n;
 
    ll sum = ((ll) n * (n + 1)) / 2;
 
    if (sum % 2 != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        ll l_sum = 0;
        vector<int> left;
        ll x = n;
 
        while (l_sum + x <= sum / 2) {
            l_sum += x;
            left.push_back(x);
            x--;
        }
        
        int aux = -1;
        if (l_sum < sum / 2) {
            aux = (sum / 2) - l_sum;
            left.push_back(aux);
        }
 
        cout << left.size() << "\n";
        for (int i: left) {
            cout << i << " ";
        }
 
        cout << "\n" << n - left.size() << "\n";
 
        while (x > 0) {
            if (x != aux) {
                cout << x << " ";
            }
            x--;
        }
 
        cout << "\n";
    }
 
    return 0;
}