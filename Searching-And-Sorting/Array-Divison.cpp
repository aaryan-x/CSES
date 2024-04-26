#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9 + 7;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool possible(ll x, vector<ll> v, ll k) {
    ll currSum = 0, subarrayCount = 1, n = v.size();
    for (int i = 0; i < n; i++) {
        if (v[i] > x) {
            return false;
        }
        if (currSum + v[i] <= x) {
            currSum += v[i];
        }else {
            if (subarrayCount == k) {
                return false;
            }
            subarrayCount++;
            currSum = v[i];
        }
    }
    return true;
}

void solve(){
    ll n, k, sum = 0;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i] % mod;
    }

    ll low = 0, high = sum + 1, ans = sum;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (possible(mid, v, k)) {
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
