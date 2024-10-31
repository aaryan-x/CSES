#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9 + 7;

void solve() {
  ll n, x;
  cin >> n >> x;

  vector<vector<char>> forest(n + 1, vector<char>(n + 1, '.'));
  vector<vector<int>> trees(n + 1, vector<int>(n + 1, 0));

  //Creating the forest
  for (int i = 1; i <= n; i++) { 
    for (int j = 1; j <= n; j++) {
      cin >> forest[i][j];
    }
  }

  //Creating the rowWise prefix sum 
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (forest[i][j] == '*')  trees[i][j] = 1 + trees[i][j - 1]; 
      else  trees[i][j] = trees[i][j - 1];
    }
  }

  //Processing the queries
  while (x--) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    
    int treeCount = 0;
    for (int i = y1; i <= y2; i++) {
      treeCount += (trees[i][x2] - trees[i][x1 - 1]);
    }
    cout << treeCount << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
