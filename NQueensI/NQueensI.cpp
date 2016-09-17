#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution{
public:
  bool isValid(vector<int>& sol){
    int n = sol.size();
    for(int i = 0; i < n - 1; i++){
      if(sol[i] == sol[n - 1] || abs(sol[i] - sol[n - 1]) == abs(i - (n - 1)))
        return false;
    }
    return true;
  }

  vector<string> transform(vector<int>& sol){
    int n = sol.size();
    vector<string> res;
    for(int i = 0; i < n; i++){
      string row = "";
      for(int j = 0; j < n; j++){
        if(j == sol[i])
          row.push_back('Q');
        else
          row.push_back('.');
      }
      res.push_back(row);
    }
    return res;
  }

  void solveNQueensHelper(int n, vector<int>& sol, vector<vector<string> >& res){
    if(!isValid(sol))
      return;

    if(sol.size() == n){
      res.push_back(transform(sol));
      return;
    }

    for(int i = 0; i < n; i++){
      sol.push_back(i);
      solveNQueensHelper(n, sol, res);
      sol.pop_back();
    }
  }

  vector<vector<string> > solveNQueens(int n){
    vector<vector<string> > res;
    vector<int> sol;
    solveNQueensHelper(n, sol, res);
    return res;
  }
};

int main(){
  int n = 4;

  Solution solution;
  vector<vector<string> > res = solution.solveNQueens(4);

  for(int i = 0; i < res.size(); i++){
    for(int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << "\n";
    cout << endl;
  }

  return 0;
}

