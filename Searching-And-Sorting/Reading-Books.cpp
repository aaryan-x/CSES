#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll sum = 0;
    vector < ll > times(n);
    for(ll i = 0; i < n; ++i) {
        cin >> times[i];
        sum += times[i];
    }
    sort(times.begin(), times.end());
    ll res = max(sum, (ll) 2 * times[n - 1]);
    cout << res << endl;
    return 0;
}
