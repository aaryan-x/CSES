#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9 + 7;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    ll n, target;
    cin >> n >> target;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i].first = x;
        v[i].second = i + 1;
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < n - 2; i++) {
        ll left = i + 1, right = n - 1;
        while (left < right) {
            ll sum = v[i].first + v[left].first + v[right].first;
            if (sum == target) {
                cout << v[i].second << " " << v[left].second << " " << v[right].second << endl;
                return;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main() {
    fast();
    int t = 1;
    solve();
    return 0;
}
