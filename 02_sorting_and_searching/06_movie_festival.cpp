#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
bool compare(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) 
        return a.first < b.first;
 
    return a.second < b.second;
}
 
int main() {
    int n;
    cin >> n;
 
    vector<pair<int, int>> x(n);
    for (auto &i: x) {
        cin >> i.first >> i.second;
    }
 
    sort(x.begin(), x.end(), compare);
    int count = 0;
    int last = -1;
    
    for (int i = 0; i < n; i++) {
        if (i == 0 || x[i].first >= last) {
            last = x[i].second;
            count++;
        }
    }
 
    cout << count << "\n";
 
    return 0;
}