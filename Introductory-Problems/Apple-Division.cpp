#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

void f(int index, ll sumA, ll sumB, vector < ll > & apples, ll & minDiff){
  if (index >= apples.size()) {
    minDiff = min(minDiff, abs(sumA - sumB));
    return;
  }
  f(index + 1, sumA + apples[index], sumB, apples, minDiff);
  f(index + 1, sumA, sumB + apples[index], apples, minDiff);
}

void solve(){
  ll n;
  cin >> n;
  vector < ll > apples(n);
  for (ll i = 0; i < n; i++) {
    cin >> apples[i];
  }

  ll minDiff = INT_MAX;
  f(0, 0, 0, apples, minDiff);
  cout << minDiff << endl;
}

int main(){
  solve();
  return 0;
}
