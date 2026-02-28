#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n, q;
  cin >> n >> q;
  vector <ll> arr(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    arr[i] = x + arr[i - 1];
  }

  while (q--) {
    ll l, r;
    cin >> l >> r;
    cout << arr[r] - arr[l - 1] << endl;
  }
  return 0;
}
