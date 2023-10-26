#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, targetSum;
    cin >> n >> targetSum;
    vector<pair<int, int>> v;
    
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back({num, i + 1});
    }

    sort(v.begin(), v.end());
    
    int left = 0, right = n - 1;
    bool isAnswerPresent = false;

    while (left < right)
    {
        int sum = v[left].first + v[right].first;
        if (sum == targetSum){
            cout << v[left].second << " " << v[right].second;
            isAnswerPresent = true;
            break;
        }
        else if (sum > targetSum){
            right--;
        }
        else{
            left++;
        }
    }

    if (!isAnswerPresent){
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
