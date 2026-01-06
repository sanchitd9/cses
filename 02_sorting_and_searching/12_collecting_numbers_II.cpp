#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n + 1);
    vector<int> index(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        index[x[i]] = i;
    }

    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (index[i] < index[i - 1]) {
            ans++;
        }
    }

    while (m--) {
        int a, b;
        cin >> a >> b;

        int i = x[a];
        int j = x[b];

        // Remove existing contribution
        if (i > 1 && index[i] < index[i - 1]) ans--;
        if (i < n && index[i] > index[i + 1]) ans--;
        if ((i != j - 1) && (j > 1) && index[j] < index[j - 1]) ans--;
        if ((i != j + 1) && (j < n) && index[j] > index[j + 1]) ans--;

        swap(x[a], x[b]);
        swap(index[i], index[j]);

        // Add new contributions
        if (i > 1 && index[i] < index[i - 1]) ans++;
        if (i < n && index[i] > index[i + 1]) ans++;
        if ((i != j - 1) && (j > 1) && index[j] < index[j - 1]) ans++;
        if ((i != j + 1) && (j < n) && index[j] > index[j + 1]) ans++;

        cout << ans << "\n";
    }

    return 0;
}