#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
 
 
int main(){
    ll n, count = 0;
    cin >> n;
 
	// Dividing n by powers of 5 and update count
	for (int i = 5; n / i >= 1; i *= 5)
		count += n / i;
 
    cout<< count<<endl;
    return 0;
}
