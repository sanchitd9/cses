#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int n;
    cin >> n;
 
    n = n - (n % 5);
 
    int sum = 0;
    while (n > 1) {
        int x = n;
        while (x % 5 == 0) {
            x /= 5;
            sum++;
        }
 
        n -= 5;
    }
 
    cout << sum << "\n";
 
    return 0;
}