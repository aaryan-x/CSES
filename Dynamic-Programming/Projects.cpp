#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

ll f(vector<ll> &search, vector<vector<ll>> &projects, vector<ll> &dp, ll n) {
    if (n < 0) return 0;  
    if (dp[n] != -1) return dp[n]; 
    
    // Binary search to find the last non-overlapping project
    ll index = lower_bound(search.begin(), search.end(), projects[n][1]) - search.begin() - 1;
    return dp[n] = max(f(search, projects, dp, n - 1), projects[n][2] + f(search, projects, dp, index));
}

void solve() {
    ll n;
    cin >> n;
    
    vector<vector<ll>> projects(n, vector<ll>(3));
    for (ll i = 0; i < n; i++) {
        cin >> projects[i][1] >> projects[i][0] >> projects[i][2]; 
    }
    
    sort(projects.begin(), projects.end());
    
    vector<ll> search(n);
    for (ll i = 0; i < n; i++) {
        search[i] = projects[i][0];  
    }
    
    vector<ll> dp(n, -1);
    cout << f(search, projects, dp, n - 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();  
    return 0;
}
