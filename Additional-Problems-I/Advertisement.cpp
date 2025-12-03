#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
  ll n;
  cin >> n;
  vector<ll> arr(n), nsl(n), nsr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  stack<ll> s;
  
  for (int i = n - 1; i >= 0; i--) {
    if (s.empty()) s.push(i);
    
    while (!s.empty() && arr[i] <= arr[s.top()]) s.pop();
    
    if (s.empty())
      nsr[i] = n;
    else {
      nsr[i] = s.top();
    }

    s.push(i);
  }

  while (!s.empty()) s.pop();

  for (int i = 0; i < n; i++) {
    if (s.empty()) s.push(i);
    
    while (!s.empty() && arr[i] <= arr[s.top()]) s.pop();

    if (s.empty())
      nsl[i] = -1;
    else
      nsl[i] = s.top();

    s.push(i);
  }

  ll maxArea = 0;
  for (int i = 0; i < n; i++) {
    maxArea = max(maxArea, arr[i] * (nsr[i] - nsl[i] - 1));
  }

  cout << maxArea << endl;
}

int main() {
  solve();
  return 0;
}
