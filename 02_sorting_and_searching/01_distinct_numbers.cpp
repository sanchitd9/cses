#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    int n;
    cin >> n;
 
    vector<int> arr(n);
    for (int &x: arr) {
        cin >> x;
    }
 
    sort(arr.begin(), arr.end());
 
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i - 1] != arr[i]) {
            count++;
        }
    }
 
    cout << count << "\n";
    
    return 0;
}