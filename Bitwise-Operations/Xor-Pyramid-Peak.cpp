#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int N = 2e5;
int power[N];

void solve() {
  ll n;
  cin >> n;
  vector<ll> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  power[0] = 0;
  power[1] = 0;
  power[2] = 1;
  for (int i = 3; i < N; i++) {
    power[i] = (i / 2) + power[i / 2];
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll c1 = power[n - 1];
    ll c2 = power[i];
    ll c3 = power[n - i - 1];

    if ((c1 - c2 - c3) <= 0) ans ^= arr[i];
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}
