#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
  Solution(vector<vector<int> > board) {
    int m = board.size();
    assert(m > 0);
    int n = board[0].size();
    assert(n > 0);

    for(int i = 0; i < m; i++) {
      accumBoard.push_back(vector<int>(n, 0));
    }
    accumBoard[0][0] = board[0][0];

    for(int j = 1; j < n; j++)
      accumBoard[0][j] = accumBoard[0][j - 1] + board[0][j];

    for(int i = 1; i < m; i++)
      accumBoard[i][0] = accumBoard[i - 1][0] + board[i][0];

    for(int i = 1; i < m; i++) {
      for(int j = 1; j < n; j++) {
          accumBoard[i][j] = accumBoard[i - 1][j] + accumBoard[i][j - 1] - accumBoard[i - 1][j - 1] + board[i][j];
      }
    }
  }

  int query(int x1, int y1, int x2, int y2) {
    if(x1 == 0 && y1 == 0)
      return accumBoard[x2][y2];
    else if(x1 == 0)
      return accumBoard[x2][y2] - accumBoard[x2][y1 - 1];
    else if(y1 == 0)
      return accumBoard[x2][y2] - accumBoard[x1 - 1][y2];
    else // if(x1 != 0 && y1 != 0)
      return accumBoard[x2][y2] + accumBoard[x1 - 1][y1 - 1] -
             accumBoard[x1 - 1][y2] - accumBoard[x2][y1 - 1];
  }
private:
  vector<vector<int> > accumBoard;
};

int main() {
  int a[4][4] = {
    {0, 0, 0, 1},
    {1, 0, 1, 0},
    {1, 1, 1, 0},
    {0, 1, 0, 1}
  };

  vector<vector<int> > board;
  for(int i = 0; i < 4; i++){
    vector<int> row = vector<int>(a[i], a[i] + 4);
    board.push_back(row);
  }

  Solution solution(board);
  cout << solution.query(0, 0, 3, 1) << endl;
  cout << solution.query(0, 1, 3, 2) << endl;
  cout << solution.query(1, 1, 3, 3) << endl;
  return 0;
}
