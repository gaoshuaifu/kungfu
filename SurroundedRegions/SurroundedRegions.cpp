/*
 * time: O(m * n), space: O(m * n)
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution{
public:
  bool isInBound(vector<vector<char> >& board, int i, int j){
    int m = board.size();
    int n = board[0].size();
    return (i >= 0 && i <= m - 1) && (j >= 0 && j <= n - 1);
  }

  void dfs(vector<vector<char> >& board, int i, int j){
    if(!isInBound(board, i, j))
      return;

    if(board[i][j] != 'o')
      return;

    board[i][j] = '.';

    dfs(board, i, j + 1);
    dfs(board, i, j - 1);
    dfs(board, i + 1, j);
    dfs(board, i - 1, j);
  }

  void solve(vector<vector<char> >& board) {
    int m = board.size();
    if(m == 0)
      return;

    int n = board[0].size();
    if(n == 0)
      return;

    for(int i = 0; i < m; i++){
      dfs(board, i, 0);
      dfs(board, i, n  - 1);
    }

    for(int j = 0; j < n; j++){
      dfs(board, 0, j);
      dfs(board, m - 1, j);
    }

    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        if(board[i][j] == 'o')
          board[i][j] = 'x';
        if(board[i][j] == '.')
          board[i][j] = 'o';
      }
    }
  }
};

int main(){
  int a[5][5] = {
    {'x', 'x', 'o', 'o', 'x'},
    {'x', 'o', 'x', 'x', 'x'},
    {'x', 'o', 'x', 'x', 'o'},
    {'x', 'x', 'o', 'x', 'o'},
    {'x', 'o', 'o', 'x', 'o'},
  };

  vector<vector<char> > board;
  for(int i = 0; i < 5; i++){
    vector<char> row = vector<char>(a[i], a[i] + 5);
    board.push_back(row);
  }

  Solution solution;
  solution.solve(board);

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++)
      cout << board[i][j];
    cout << "\n";
  }

  return 0;
}
