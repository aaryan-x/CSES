#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9 + 7;

bool dfs(int node, int parentNode, int& start, int& end, vector<int> &parent, vector<vector<int>> &adj, vector<bool> &vis) {
    vis[node] = true;
    parent[node] = parentNode;
  
    for (auto it : adj[node]){
        if (!vis[it]){
            if(dfs(it, node,start, end, parent, adj, vis)) {
                return true;
            }
        } else if (it != parentNode) {
            start = it;
            end = node;
            return true;
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1, false);
    vector<int> parent(n + 1, -1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
  
    int start = -1, end = -1;
    bool hasCycle = false;
    vector<int> cycle;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, start, end, parent, adj, vis)) {
                hasCycle = true;
                for (int j = end; j != start; j = parent[j]) {
                    cycle.push_back(j);
                }
                cycle.push_back(start); 
                cycle.push_back(end);
                break;
            }
        }
    }

    if (!hasCycle) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << cycle.size() << endl;
        reverse(cycle.begin(), cycle.end());
        for (auto it : cycle) {
            cout << it << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
