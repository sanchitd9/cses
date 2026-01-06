#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int n;
    cin >> n;

    vector<int> k(n);
    for (int &i: k) {
        cin >> i;
    }

    vector<int> towers;
    for (int i: k) {
        auto it = upper_bound(towers.begin(), towers.end(), i);
        if (it == towers.end()) {
            towers.push_back(i);
        } else {
            *it = i;
        }
    }

    cout << towers.size() << "\n";

    return 0;
}