#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int n;
    cin >> n;

    vector<int> index(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        index[x] = i;
    }

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (index[i] < index[i - 1]) {
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}