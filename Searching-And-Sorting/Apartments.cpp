#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector <ll> a(n), b(m);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
 
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
 
    ll ans = 0, i = 0, j = 0;
    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= k) {
            ans++;
            i++;
            j++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
 
    cout << ans << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
