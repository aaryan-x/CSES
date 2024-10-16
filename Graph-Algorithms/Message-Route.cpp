#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9 + 7;

void bfs(vector<vector<int>>& adj, vector<bool> & vis, vector<int>& parent){
    queue<int> q;
    q.push(0);
    vis[0] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = true;
                parent[it] = node;
                q.push(it);
            }
        }
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);
    vector<int> parent(n, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    bfs(adj, vis, parent);
    
    if (!vis[n - 1]) {
        cout << "IMPOSSIBLE" << endl; // Check if a path to node n exists
        return;
    }
    
    vector<int> path;
    for (int v = n - 1; v != -1; v = parent[v]) {
        path.push_back(v + 1); // Convert 0-based index back to 1-based
    }
    cout << path.size() << endl;
    reverse(path.begin(), path.end());

    for (int it : path) {
        cout << it << " ";
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
