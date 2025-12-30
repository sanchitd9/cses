#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int n;
    cin >> n;
 
    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        times.push_back(make_pair(a, 1));
        times.push_back(make_pair(b, -1));
    }
 
    sort(times.begin(), times.end());
 
    int sum = 0;
    int ans = 0;
 
    for (int i = 0; i < 2 * n; i++) {
        if (times[i].second == 1) sum++;
        else sum--;
 
        ans = max(ans, sum);
    }
 
    cout << ans << "\n";
 
    return 0;
}