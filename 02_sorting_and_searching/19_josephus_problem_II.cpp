#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    int n, k;
    cin >> n >> k;

    indexed_set<int> v;
    for (int i = 1; i <= n; i++) {
        v.insert(i);
    }

    int index = 0;
    for (int i = 1; i <= n; i++) {
        index = (index + k) % (n - i + 1);
        auto it = v.find_by_order(index);
        cout << *it << " ";
        v.erase(it);
    }
    cout << "\n";

    return 0;
}