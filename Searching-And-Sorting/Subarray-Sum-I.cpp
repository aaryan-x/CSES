#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    ll n, x;
    cin >> n >> x;
    vector < ll > v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll count = 0, currSum = 0;
    map < ll, ll > mp;
    mp[0] = 1;
    for(int i = 0; i < n; i++) {
        currSum += v[i];
        count += mp[currSum - x];
        mp[currSum]++;
    }
    cout << count << endl;
}

int main() {
    solve();
    return 0;
}
