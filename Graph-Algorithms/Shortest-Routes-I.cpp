#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        ll u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    const ll INF = 1e18;
    vector<ll> distances(n + 1, INF);
    distances[1] = 0;

    priority_queue<
        pair<ll, ll>,
        vector<pair<ll, ll>>,
        greater<pair<ll, ll>>
    > pq;

    pq.push({0, 1}); // {distance, node}

    while (!pq.empty()) {
        auto [dis, node] = pq.top();
        pq.pop();

        if (dis > distances[node]) continue;

        for (auto &it : adj[node]) {
            ll nextNode = it.first;
            ll newDis = dis + it.second;

            if (newDis < distances[nextNode]) {
                distances[nextNode] = newDis;
                pq.push({newDis, nextNode});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (distances[i] == INF) cout << "-1 ";
        else cout << distances[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
