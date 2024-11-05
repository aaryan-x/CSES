#include <bits/stdc++.h>
using namespace std;

void dfs(int employee, vector<vector<int>>& adj, vector<int>& subordinates) {
    subordinates[employee] = 0; 
    for (int child : adj[employee]) {
        dfs(child, adj, subordinates); 
        subordinates[employee] += subordinates[child] + 1;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; ++i) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i); 
    }

    vector<int> subordinates(n + 1, 0);
    dfs(1, adj, subordinates); 

    for (int i = 1; i <= n; ++i) {
        cout << subordinates[i] << " ";
    }
    return 0;
}
