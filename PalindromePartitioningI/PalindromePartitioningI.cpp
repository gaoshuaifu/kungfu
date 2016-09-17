#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  bool isPalindrome(string s, int start, int end){
    int i = start;
    int j = end;
    while(i <= j){
      if(s[i++] != s[j--])
        return false;
    }
    return true;
  }

  void partitionHelper(string s, int start, vector<string>& sol, vector<vector<string> >& res){
    if(start == s.size()){
      res.push_back(sol);
      return;
    }

    for(int end = start; end < s.size(); end++){
      if(isPalindrome(s, start, end)){
        sol.push_back(s.substr(start, end - start + 1));
        partitionHelper(s, end + 1, sol, res);
        sol.pop_back();
      }
    }
  }

  vector<vector<string> > partition(string s){
    vector<vector<string> > res;
    vector<string> sol;
    partitionHelper(s, 0, sol, res);
    return res;
  }
};

int main(){
  string s = "abbaca";
  Solution solution;
  vector<vector<string> > res = solution.partition(s);
  for(int i = 0; i < res.size(); i++){
    for(int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << "\n";
  }
  return 0;
}
