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
        cin >> v[i].first;
        v[i].second = i + 1;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            ll left = j + 1, right = n - 1;
            while (left < right) {
                ll sum = v[i].first + v[j].first + v[left].first + v[right].first;
                if (sum == target) {
                    cout << v[i].second << " " << v[j].second << " " << v[left].second << " " << v[right].second << endl;
                    return;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main() {
    fast();
    solve();
    return 0;
}
