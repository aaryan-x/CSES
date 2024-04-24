#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 +7;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    fast();
    int n, targetSum;
    cin >> n >> targetSum;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back({num, i + 1});
    }

    sort(v.begin(), v.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = v[left].first + v[right].first;
        if (sum == targetSum) {
            cout << v[left].second << " " << v[right].second;
            return 0;
        } else if (sum > targetSum) {
            right--;
        } else {
            left++;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
