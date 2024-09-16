#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9 + 7;

ll numofWays(ll n, ll target) {
  vector<vector<ll>> dp(n, vector <ll> (target + 1, 0));
  for (ll i = 0; i < n; i++) {
    dp[i][0] = 1;
  }

  for (ll i = 1; i < n; i++){
    for (ll j = 0; j <= target; j++) {
      ll notTake = dp[i-1][j] % mod;
      ll take = 0;
      if (j >= i) {
        take = dp[i-1][j-i] % mod;
      }
      dp[i][j] = (take + notTake) % mod;
    }
  }

  return dp[n-1][target];
}

void solve() {
  ll n;
  cin >> n;
  ll sum = n * (n + 1) / 2;
  if (sum % 2 != 0) {
    cout << 0 << endl;
  } else {
    ll target = sum / 2;
    cout << numofWays(n, target) << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
