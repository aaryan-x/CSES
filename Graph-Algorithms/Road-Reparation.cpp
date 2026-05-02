#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, size;
    int components;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
        components = n;
    }

    int findParent(int node) {
        while (node != parent[node]) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    bool unionBySize(int x, int y) {
        int px = findParent(x);
        int py = findParent(y);

        if (px == py) return false;

        if (size[px] >= size[py]) {
            parent[py] = px;
            size[px] += size[py];
        } else {
            parent[px] = py;
            size[py] += size[px];
        }

        components--;
        return true;
    }

    int getComponents() {
        return components;
    }
};

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int,int>>> roads;
    roads.reserve(m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        roads.push_back({w, {u-1, v-1}});
    }

    sort(roads.begin(), roads.end());

    DisjointSet dsu(n);
    long long totalCost = 0;
    int edgesUsed = 0;

    for (auto &r : roads) {
        if (dsu.unionBySize(r.second.first, r.second.second)) {
            totalCost += r.first;
            edgesUsed++;
        }
    }

    if (edgesUsed != n - 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << totalCost << "\n";
    }
}

int main() {
    solve();
}
