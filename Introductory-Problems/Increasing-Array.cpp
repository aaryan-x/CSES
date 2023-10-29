#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli solve(lli n, lli array[]){
    lli counter = 0;
    for (int i = 1; i < n; i++){
        if (array[i] < array[i - 1]){
            counter += (array[i - 1] - array[i]);
            array[i] = array[i - 1];
        }
    }

    return counter;
}

int main(){
    lli n;
    cin >> n;
    lli array[n];
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }

    cout << solve(n, array) << endl;
    return 0;
}
