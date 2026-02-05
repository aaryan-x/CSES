#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e12;

void shortestDistance(vector<vector<ll>> &grid){
    ll n = grid.size() - 1;  // actual number of nodes

    for(ll k = 1; k <= n; k++){
        for(ll i = 1; i <= n; i++){
            for(ll j = 1; j <= n; j++){
                if (grid[i][k] < INF && grid[k][j] < INF) {
                    grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                }
            }
        }
    }
}

void solve(){
    ll n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> grid(n + 1, vector<ll>(n + 1, INF));

    for(ll i = 1; i <= n; i++) grid[i][i] = 0;

    for(ll i = 0; i < m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        grid[u][v] = min(grid[u][v], w);
        grid[v][u] = min(grid[v][u], w);
    }

    shortestDistance(grid);

    while(q--){
        ll a, b;
        cin >> a >> b;
        if(grid[a][b] == INF) cout << -1 << '\n';
        else cout << grid[a][b] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
