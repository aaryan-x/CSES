#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> prefix;

ll sum(ll i, ll j){
    if(i == 0) return prefix[j];
    else    return prefix[j] - prefix[i-1];
}
void solve(){
    int n;
    cin >> n;
    prefix.resize(n);
    vector<ll> a(n);

    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if(i == 0)
            prefix[i] = a[i];
        else
            prefix[i] = a[i] + prefix[i - 1];
    }

    for (int i = n - 1; i >= 0; i--){
        dp[i][i] = a[i];
        for (int j = i + 1; j < n; j++){
            ll pickLeft = sum(i, j) - dp[i+1][j];
            ll pickRight = sum(i, j) - dp[i][j-1];
            dp[i][j] = max(pickLeft, pickRight);
        }
    }

    cout << dp[0][n - 1] << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    solve();
    return 0;
}
