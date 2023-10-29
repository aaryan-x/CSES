#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

void solve(lli n){
    if (n == 1)
        cout << n << endl;
    else if (n <= 3)
        cout << "NO SOLUTION";
    else{
        for (int i = 2; i <= n; i += 2){
            cout << i << " ";
        }
        for (int i = 1; i <= n; i += 2){
            cout << i << " ";
        }
    }
}

int main(){
    lli n;
    cin >> n;
    solve(n);
    return 0;
}
