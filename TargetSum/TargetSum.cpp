/*
Question:
  123456789 = 100 (also known as targetSum). Using standard integer arithmetic
  operators +, -, how many different solutions can you find by inserting the
  operators between some digits?

All combinations that sums up to 100:
  -1+2-3+4+5+6+78+9
  1+2+3-4+5+6+78+9
  1+2+34-5+67-8+9
  1+23-4+5+6+78-9
  1+23-4+56+7+8+9
  12+3+4+5-6-7+89
  12+3-4+5+67+8+9
  12-3-4+5-6+7+89
  123+4-5+67-89
  123+45-67+8-9
  123-4-5-6-7+8-9
  123-45-67+89
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void partitionHelper(string& str, int target, int start, vector<int>& sol, vector<vector<int> >& res) {
    if (start == str.size()) {
      if(target == 0)
        res.push_back(sol);
      return;
    }

    for(int end = start; end < str.size(); end++) {
      int value = stoi(str.substr(start, end - start + 1));

      sol.push_back(value);
      partitionHelper(str, target - value, end + 1, sol, res);
      sol.pop_back();

      sol.push_back(-value);
      partitionHelper(str, target + value, end + 1, sol, res);
      sol.pop_back();
    }
  }

  vector<vector<int> > partition(string& str, int target) {
    vector<vector<int> > res;
    vector<int> sol;
    partitionHelper(str, target, 0, sol, res);
    return res;
  }
};

int main(){
  string str = "123456789";
  int target = 100;
  Solution solution;
  vector<vector<int> > res = solution.partition(str, target);
  for(int i = 0; i < res.size(); i++) {
  for(int j = 0; j < res[i].size(); j++) {
    if (res[i][j] >= 0) {
    cout << '+';
    }
    cout << res[i][j];
  }
  cout << "\n";
  }
  return 0;
}
