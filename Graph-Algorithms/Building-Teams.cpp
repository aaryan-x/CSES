#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    vector<int> color(n + 1, -1);   // -1 means uncolored, 1 and 2 are the team labels
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto bfs = [&](int start) -> bool {
        queue<int> q;
        q.push(start);
        color[start] = 1;
        
        while (!q.empty()){
            int node = q.front();
            q.pop();
            
            for (int it : adj[node]){
                if (color[it] == -1){
                    color[it] = 3 - color[node];
                    q.push(it);
                } else if (color[it] == color[node]) {
                    // Conflict: same team for adjacent nodes
                    return false;
                }
            }
        }
        return true;
    };
    
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) { // Unvisited node
            if (!bfs(i)) {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
