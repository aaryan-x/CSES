#include <bits/stdc++.h>
using namespace std;

/*Using 2-pointer approach*/
int gondolas(int n, int x, int children[]){
    int gondola = 0;
    int left = 0, right = n - 1;
    while (left <= right){
        if (children[left] + children[right] <= x){
            gondola++;
            left++;
            right--;
        }
        else{
            if (children[right] <= x){
                gondola++;
            }
            right--;
        }
    }
  
    return gondola;
}

int main(){

    long long int n, x;
    cin >> n >> x;

    int children[n];
    for (int i = 0; i < n; i++){
        cin >> children[i];
    }

    sort(children, children + n);
    cout << gondolas(n, x, children) << endl;
    return 0;
}
