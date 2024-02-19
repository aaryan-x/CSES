#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007;
typedef long long int ll;

void bitStrings(ll n){
    ll ans = 1;
    while(n--){
        ans *=2;
        ans %=mod;
    }
    cout<<ans;
}

int main() {
    ll n;
    cin>> n;
    bitStrings(n);
    return 0;
}
