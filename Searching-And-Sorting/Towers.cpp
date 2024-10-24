#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  ll n;
  cin >> n;
  vector <ll> heights(n);
  for (int i = 0; i < n; i++) {
    cin >> heights[i];
  }

  vector <int> towers;
  for (int i = 0; i < n; i++) {
    int h = heights[i];
    auto it = upper_bound(towers.begin(), towers.end(), h);
    
    if (it == towers.end())  towers.push_back(h);
    else   *it = h;
  }

  cout << towers.size() << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
