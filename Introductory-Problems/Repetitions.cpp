#include <bits/stdc++.h>
using namespace std;

int maxSubString(string str){
    int max = 0, count = 1;
    for (int i = 0; i < str.size(); i++){
        if (str[i] == str[i + 1]){
            count++;
            if (count >= max){
                max = count;
            }
        }
        else{
            count = 1;
        }
    }
  
    return max;
}

int main(){
    string str;
    cin >> str;
    cout << maxSubString(str) << endl;
    return 0;
}
