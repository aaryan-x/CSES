#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

void solve(lli n, lli sticks[]){
    sort(sticks, sticks + n);
    lli median = sticks[n / 2];
    lli value = 0;
    for (int i = 0; i < n; i++){
        value += abs(sticks[i] - median);
    }
    cout << value << endl;
}

int main(){
    lli n;
    cin >> n;
    lli sticks[n];
    for (int i = 0; i < n; i++){
        cin >> sticks[i];
    }

    solve(n, sticks);
    return 0;
}

/* In this approach, we sort the array in O(nlogn), where we find the difference in value of elements of array and sum them up to find the cost of operations.
Another approach is to find the average of the elements and then finding the difference of elements and the average of elements,
where we can use the float value of the avg and then round the sum of differences.
*/
