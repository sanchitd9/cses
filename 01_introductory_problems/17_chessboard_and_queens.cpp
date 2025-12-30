#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
bool is_valid(vector<vector<char>> &board, int r, int c, int n) {
    if (board[r][c] == '*') {
        return false;
    }
 
    // Column
    for (int i = r - 1; i >= 0; i--) {
        if (board[i][c] == 'Q') {
            return false;
        }
    }
 
    // Diagonal 1
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
 
    // Diagonal 2
    for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
 
    return true;
}
 
int helper(vector<vector<char>> &board, int r, int c, const int n) {
    if (r == n) {
        return 1;
    }
 
    int ways = 0;
    for (int i = 0; i < n; i++) {
        if (is_valid(board, r, i, n)) {
            board[r][i] = 'Q';
            ways += helper(board, r + 1, 0, n);
            board[r][i] = '.';
        }
    }
 
    return ways;
}
 
int main() {
    const int n = 8;
 
    vector<vector<char>> board(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
 
    int ans = helper(board, 0, 0, n);
    cout << ans << "\n";    
 
    return 0;
}