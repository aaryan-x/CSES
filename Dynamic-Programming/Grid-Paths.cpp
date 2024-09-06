#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vector<vector<char>> matrix(n, vector<char>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    
    if (matrix[0][0] != '*') dp[0][0] = 1;
    
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (matrix[i][j] == '*') {
                dp[i][j] = 0; 
            } else {
                // Compute the number of ways from top or left
                if (i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    cout << dp[n-1][n-1] << endl;
}

int main() {
    solve();
    return 0;
}
