#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int x = 0;
        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            x ^= a;
        }
      
        if (x != 0){
            cout << "first" << endl;
        }
        else{
            cout << "second" << endl;
        }
    }
    return 0;
}
