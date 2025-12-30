#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    string s;
    cin >> s;
 
    int curr = 1;
    int ans = 1;
 
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            curr++;
        } else {
            curr = 1;
        }
 
        ans = max(curr, ans);
    }
 
    cout << ans << "\n";
 
    return 0;
}