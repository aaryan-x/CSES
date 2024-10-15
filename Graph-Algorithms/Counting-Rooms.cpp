#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9 + 7;

void dfs(int i, int j, int n, int m, vector < vector < char >> & grid, vector < vector < bool >> & vis) {
  if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '#' || vis[i][j]) return;

  vis[i][j] = true;

  dfs(i - 1, j, n, m, grid, vis);
  dfs(i + 1, j, n, m, grid, vis);
  dfs(i, j - 1, n, m, grid, vis);
  dfs(i, j + 1, n, m, grid, vis);
}

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector <char> (m, 0));
  vector<vector<bool>> vis(n, vector <bool> (m, false));
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '.' && vis[i][j] == false){
        count++;
        dfs(i, j, n, m, grid, vis);
      }
    }
  }

  cout << count << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
