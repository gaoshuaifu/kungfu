#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution{
public:
  void combinationSum2Helper(vector<int>& candidates, int target, int start, vector<int>& sol, vector<vector<int> >& res){
    if(target == 0){
      res.push_back(sol);
      return;
    }

    if(target < 0){
      return;
    }

    for(int i = start; i < candidates.size(); i++){
      if (i > start && candidates[i] == candidates[i-1]) {
        continue;
      }
      sol.push_back(candidates[i]);
      combinationSum2Helper(candidates, target - candidates[i], i + 1, sol, res);
      sol.pop_back();
    }
  }

  vector<vector<int> > combinationSum2(vector<int> candidates, int target){
    sort(candidates.begin(), candidates.end());
    vector<vector<int> > res;
    vector<int> sol;
    combinationSum2Helper(candidates, target, 0, sol, res);
    return res;
  }
};

int main(){
  vector<int> candidates;
  candidates.push_back(10);
  candidates.push_back(1);
  candidates.push_back(2);
  candidates.push_back(7);
  candidates.push_back(6);
  candidates.push_back(1);
  candidates.push_back(5);


  int target = 8;

  Solution solution;
  vector<vector<int> > res = solution.solSum2(candidates, target);

  for(int i = 0; i < res.size(); i++){
    for(int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << "\n";
  }
  cout << endl;

  return 0;
}
