#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
  ll a,b;
  cin>>a>>b;
 
  if( (a+b) % 3 == 0 && max(a,b) <= 2 * min(a,b))  cout<<"YES"<<endl;
  else  cout<<"NO"<<endl;
}
 
int main() {
    ll n;
    cin >> n;
    while(n--)  solve();
    return 0;
}
