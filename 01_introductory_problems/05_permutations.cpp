#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int n;
    cin >> n;
 
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
    } else {
        for (int i = n; i > 0; i--) {
            if (i % 2 != 0) {
                cout << i << " ";
            }
        }
 
        for (int i = n; i > 0; i--) {
            if (i % 2 == 0) {
                cout << i << " ";
            }
        }
    }
 
    cout << "\n";
 
    return 0;
}