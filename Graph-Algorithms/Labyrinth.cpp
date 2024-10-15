#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Direction {
    int dx, dy;
    char dir;
};

bool isValid(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#' && !vis[i][j];
}

void solve() {
    ll n, m;
    cin >> n >> m;
    
    int startX = -1, startY = -1;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    
    // Directions array: up, down, left, right
    vector<Direction> directions = {{-1, 0, 'U'}, {1, 0, 'D'}, {0, -1, 'L'}, {0, 1, 'R'}};
    
    // Input the grid and locate the start position 'A'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                startX = i;
                startY = j;
            }
        }
    }
    
    // Parent array to reconstruct the path
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> pathDirection(n, vector<char>(m, '\0'));

    queue<pair<int, int>> q;
    q.push({startX, startY});
    vis[startX][startY] = true;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        if (grid[x][y] == 'B') {
            // Reconstruct the path
            string path;
            while (grid[x][y] != 'A') {
                path.push_back(pathDirection[x][y]);
                auto [px, py] = parent[x][y];
                x = px;
                y = py;
            }
            reverse(path.begin(), path.end());
            cout << "YES" << endl;
            cout << path.size() << endl;
            cout << path << endl;
            return;
        }
        
        // Explore all four directions
        for (auto& d : directions) {
            int nx = x + d.dx;
            int ny = y + d.dy;
            
            if (isValid(nx, ny, n, m, grid, vis)) {
                vis[nx][ny] = true;
                parent[nx][ny] = {x, y};  // Track where we came from
                pathDirection[nx][ny] = d.dir;  // Track the direction we took
                q.push({nx, ny});
            }
        }
    }
    
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
