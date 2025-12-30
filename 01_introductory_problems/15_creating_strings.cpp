#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
void solve(string &s, int i, set<string> &ans) {
    if (i >= s.size()) {
        ans.insert(s);
        return;
    }
 
    for (int j = i; j < s.size(); j++) {
        swap(s[i], s[j]);
        solve(s, i + 1, ans);
        swap(s[i], s[j]);
    }
}
 
int main() {
    string s;
    cin >> s;
 
    set<string> st;
    solve(s, 0, st);
 
    cout << st.size() << "\n";
    for (auto s: st) {
        cout << s << "\n";
    }
 
    return 0;
}