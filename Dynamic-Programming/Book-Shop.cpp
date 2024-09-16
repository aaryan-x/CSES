#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9 + 7;

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> prices(n, 0), pages(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    vector<ll> prev(x + 1, 0), curr(x + 1, 0);

    for (int j = 0; j <= x; j++) {
        if (j >= prices[0]) {
            prev[j] = pages[0];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            ll pick = INT_MIN;
            if (j >= prices[i]) {
                pick = (pages[i] + prev[j - prices[i]]) % mod;
            }
            ll notPick = prev[j];

            curr[j] = max(pick, notPick);
        }
        prev = curr;
    }
    cout << prev[x] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
