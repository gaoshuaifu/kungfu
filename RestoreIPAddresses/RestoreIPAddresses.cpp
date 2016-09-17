#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;


class Solution {
public:
  bool isValid(string& s, int start, int end){
    string str = s.substr(start, end - start + 1);
    int n = str.size();
    if(n == 1)
      return str >= "0" && str <= "9";
    if(n == 2)
      return str >= "10" && str <= "99";
    if(n == 3)
      return str >= "100" && str <= "255";
    else
      return false;
  }

  string transform(vector<string>& sol){
    assert(sol.size() == 4);
    string str = "";
    for(int i = 0; i < 3; i++){
      str += sol[i];
      str += ".";
    }
    str += sol[3];
    return str;
  }

  void restoreIpAddressesHelper(string& s, int start, vector<string>& sol, vector<string>& res){
    if(sol.size() == 4){
      if(start == s.size())
        res.push_back(transform(sol));
      return;
    }

    for(int end = start; end < min(start + 3, (int)s.size()); end++){
      if(isValid(s, start, end)){
        sol.push_back(s.substr(start, end - start + 1));
        restoreIpAddressesHelper(s, end + 1, sol, res);
        sol.pop_back();
      }
    }
  }

  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    vector<string> sol;
    restoreIpAddressesHelper(s, 0, sol, res);
    return res;
  }
};

int main(){
  string s = "25525511135";
  Solution solution;
  vector<string> res = solution.restoreIpAddresses(s);
  for(int i = 0; i < res.size(); i++)
    cout << res[i] << "\n";
  return 0;
}

