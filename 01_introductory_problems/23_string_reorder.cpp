#include <bits/stdc++.h>

using namespace std;

bool is_valid(int n, int maxi) {
    return maxi <= (n + 1) / 2;
}

int main() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> mp(26, 0);
    for (char ch : s) {
        mp[ch - 'A']++;
    }

    int maxi = *max_element(mp.begin(), mp.end());

    if (!is_valid(n, maxi)) {
        cout << -1 << "\n";
    } else {
        int index = 0;
        char prev = '*';
        while (index < n) {
            for (int i = 0; i < 26; i++) {
                char curr = (char) (i + 'A');
                if (mp[i] > 0 && curr != prev) {
                    mp[i]--;
                    if (is_valid(n - index - 1, *max_element(mp.begin(), mp.end()))) {
                        s[index] = curr;
                        prev = curr;
                        index++;
                        break;
                    } else {
                        mp[i]++;
                    }
                }
                
            }
        }

        cout << s << "\n";
    }

    return 0;
}