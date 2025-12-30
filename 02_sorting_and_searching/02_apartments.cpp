#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int n, m, k;
    cin >> n >> m >> k;
 
    vector<int> x(n);
    for (int &i: x) {
        cin >> i;
    }
 
    vector<int> b(m);
    for (int &i: b) {
        cin >> i;
    }
 
    sort(x.begin(), x.end());
    sort(b.begin(), b.end());
 
    int i = 0, j = 0;
    int count = 0;
    while (i < n && j < m) {
        if (b[j] - k > x[i]) {
            i++;
        } else if (b[j] + k < x[i]) {
            j++;
        } else {
            i++;
            j++;
            count++;
        }
    }
 
    cout << count << "\n";
 
    return 0;
}