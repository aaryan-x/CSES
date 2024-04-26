#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9 + 7;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool possible(ll x, vector<ll> v, ll t) {
    ll n = v.size();
    double products = 0;
    for (int i = 0; i < n; i++){
        products += (x/v[i]);
    }
    return products >= t;
}

void solve() {
    ll n, t, mx = INT_MIN;
    cin >> n >> t;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }

    ll low = 0, high = 1e18 + 5;
    ll ans = mx * t;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (possible(mid, v, t)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}

int main() {
    fast();
    solve();
    return 0;
}
