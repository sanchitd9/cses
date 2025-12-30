#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int n;
    cin >> n;
 
    vector<string> ans = {"0", "1"};
    for (int i = 1; i < n; i++) {
        vector<string> left;
        for (string &s: ans) {
            left.push_back(s + "0");
        }
 
        vector<string> right;
        for (string &s: ans) {
            right.push_back(s + "1");
        }
 
        reverse(right.begin(), right.end());
 
        for (string &s: right) {
            left.push_back(s);
        }
 
        ans = left;
    }
    
    for (string &x: ans) {
        cout << x << "\n";
    }
 
    return 0;
}