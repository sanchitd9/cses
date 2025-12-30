#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    string s;
    cin >> s;
 
    unordered_map<char, int> mp;
    for (char ch: s) {
        mp[ch]++;
    }
 
    bool flag = false;
    for (auto x: mp) {
        if (flag && x.second % 2 != 0) {
            cout << "NO SOLUTION\n";
            return 0;
        }
 
        if (x.second % 2 != 0) {
            flag = true;
        }
    }
 
    string ans(s.size(), '-');
    int l = 0, r = (int) s.size() - 1;
    for (auto &x: mp) {
        if (x.second % 2 == 0) {
            while (x.second > 0) {
                ans[l] = ans[r] = x.first;
                x.second -= 2;
                l++;
                r--;
            }
        } else {
            while (x.second > 1) {
                ans[l] = ans[r] = x.first;
                x.second -= 2;
                l++;
                r--;
            }
        }
    }
 
    for (auto x: mp) {
        if (x.second == 1) {
            ans[l] = x.first;
        }
    }
 
    cout << ans << "\n";
    
    return 0;
}