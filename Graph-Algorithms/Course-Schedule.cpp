#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1); 
    vector<int> indegree(n + 1, 0); 
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    
    queue<int> q;
    vector<int> res;
    
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)  q.push(i);
    }
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        res.push_back(node);
        
        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0)  q.push(it);
        }
    }
    
    if (res.size() != n) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (auto it : res) {
            cout << it << " ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
