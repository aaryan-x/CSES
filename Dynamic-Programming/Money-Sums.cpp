#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    ll n, total = 0;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }
   
    vector<ll> dp(total + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = total; j >= arr[i]; j--) {
            if (dp[j - arr[i]] == 1) {
                dp[j] = 1;
            }
        }
    }
    
    ll count = 0;
    for (int i = 1; i <= total; i++) {
        if (dp[i] == 1) {
            count++;
        }
    }
    
    cout << count << endl;
    for (int i = 1; i <= total; i++) {
        if (dp[i] == 1) {
            cout << i << " ";
        }
    }
}

int main() {
    solve();
    return 0;
}
