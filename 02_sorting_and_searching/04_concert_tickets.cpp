#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int n, m;
    cin >> n >> m;
 
    vector<int> h(n);
    for (int &i: h) {
        cin >> i;
    }
 
    vector<int> t(m);
    for (int &i: t) {
        cin >> i;
    }
 
    multiset mp(h.begin(), h.end());
 
    for (int x: t) {
        auto it = mp.lower_bound(x);
 
        if (*it == x) {
            cout << (*it);
            mp.erase(it);
        } else if (it == mp.begin()) {
            cout << -1;
        } else {
            cout << *prev(it);
            mp.erase(prev(it));
        }
        cout << "\n";
    }
 
    return 0;
}