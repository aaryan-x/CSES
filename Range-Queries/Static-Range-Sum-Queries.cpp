#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9 + 7;

void solve() {
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n + 1, 0);
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }

  while (q--) {
    ll x, y;
    cin >> x >> y;
    ll rangeSum = a[y] - a[x - 1];
    cout << rangeSum << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
