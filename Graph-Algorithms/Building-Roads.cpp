#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9 + 7;

void dfs(int node, vector<vector<int>> &adj, vector<bool>& vis){
    vis[node]= true;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis);  
        }
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    int count = 0;
    vector<int> city;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            count++;
            city.push_back(i + 1); // store the original 1-based index
            dfs(i, adj, vis);
        }
    }
    
    cout << count - 1 << endl; // number of extra edges needed to connect components
    if(count > 1){
        int source = city[0];
        for(int i = 1; i < city.size(); i++){
            cout << source << " " << city[i] << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
