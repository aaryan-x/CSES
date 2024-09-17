#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9 + 7;

void solve() {
  ll n;
  cin >> n;
  vector<ll> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= 6 && i - j >= 0; j++) {
      dp[i] = (dp[i] + dp[i - j]) % mod;
    }
  }
  cout << dp[n] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
