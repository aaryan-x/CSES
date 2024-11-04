#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9 + 7;

void solve() {
  ll n;
  cin >> n;
  vector<ll> dp(n + 1, 1e9);
  dp[0] = 0;
  
  for (int i = 1; i <= n; i++) {
    int curr = i;
    while (curr > 0) {
      int digit = curr % 10;
      curr /= 10;
      dp[i] = min(dp[i], dp[i - digit] + 1);
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
