#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }

    for (int i = 0; i < v.size(); i++) {
        if (i % 2 == 0) {
            v.push_back(v[i]);
        } else {
            cout << v[i] << " ";
        }
    }
    cout << "\n";

    return 0;
}