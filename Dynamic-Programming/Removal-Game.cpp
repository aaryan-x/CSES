#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n), prefix(n); // Prefix Sum Vector

    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    vector<vector<ll>> sum(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if(i == 0)
            prefix[i] = a[i];
        else
            prefix[i] = a[i] + prefix[i - 1];
    }


    // Calculating sum of subarrays from i to j using prefix sum
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (i == 0)
                sum[i][j] = prefix[j];
            else
                sum[i][j] = prefix[j] - prefix[i - 1];
        }
    }

    for (int i = n - 1; i >= 0; i--){
        dp[i][i] = a[i];
        for (int j = i + 1; j < n; j++){
            // dp[i][j] is the total sum from i to j and leaving the minimum sum for player 2
            dp[i][j] = sum[i][j] - min(dp[i + 1][j], dp[i][j - 1]);
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
