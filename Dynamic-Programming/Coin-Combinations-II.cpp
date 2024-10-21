#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;
 
void solve(){
  ll n, target;
  cin>>n>>target;
  vector<ll> coins(n);
  for(ll i=0;i<n;i++){
    cin>>coins[i];
  }
  vector<ll> dp(target+1, 0);
  dp[0]=1;
  
  for(int i=0;i<n;i++){
    for(int j =0; j<=target;j++){
      if(j>=coins[i]){
        dp[j] = (dp[j] + dp[j-coins[i]])%mod;
      }
    }
  }
  
  cout<<dp[target]<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
