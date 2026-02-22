#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> vis;

// directions: U, D, R, L
vector<pair<int,int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
vector<char> moves = {'U','D','R','L'};

int main(){
    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    vis.assign(n, vector<bool>(m, false));

    pair<int,int> src, dest;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A') src = {i, j};
            if(grid[i][j] == 'B') dest = {i, j};
        }
    }

    // parent direction used to reach (i,j)
    vector<vector<int>> parentDir(n, vector<int>(m, -1));

    queue<pair<int,int>> q;
    q.push(src);
    vis[src.first][src.second] = true;

    bool found = false;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        if(x == dest.first && y == dest.second){
            found = true;
            break;
        }

        for(int i = 0; i < 4; i++){
            int nx = x + directions[i].first;
            int ny = y + directions[i].second;

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(grid[nx][ny] == '#') continue;
            if(vis[nx][ny]) continue;

            vis[nx][ny] = true;
            parentDir[nx][ny] = i;   // store move index
            q.push({nx, ny});
        }
    }

    if(!found){
        cout << "NO\n";
        return 0;
    }

    // Reconstruct path
    string path;
    int x = dest.first, y = dest.second;

    while(make_pair(x, y) != src){
        int d = parentDir[x][y];
        path.push_back(moves[d]);
        x -= directions[d].first;
        y -= directions[d].second;
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";

    return 0;
}
