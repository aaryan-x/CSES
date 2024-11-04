#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<char>>& board, int n) {
  // Check this row on the left side
  for (int i = 0; i < col; i++) {
    if (board[row][i] == 'Q')  return false;
  }

  // Check upper diagonal on the left side
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j] == 'Q')  return false;
  }

  // Check lower diagonal on the left side
  for (int i = row, j = col; i < n && j >= 0; i++, j--) {
    if (board[i][j] == 'Q')  return false;
  }

  return true;
}

void help(int col, vector<vector<char>>& board, int& ansCount) {
  if (col == 8) {
    ansCount++;
    return;
  }
  for (int row = 0; row < 8; row++) {
    if (board[row][col] == '.' && isSafe(row, col, board, 8)) {
      board[row][col] = 'Q';
      help(col + 1, board, ansCount);
      board[row][col] = '.';
    }
  }
}

void solve() {
  vector<vector<char>> board(8, vector<char>(8));
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> board[i][j];
    }
  }
  int ansCount = 0;
  help(0, board, ansCount);
  cout << ansCount << endl;
}

int main() {
  solve();
  return 0;
}
