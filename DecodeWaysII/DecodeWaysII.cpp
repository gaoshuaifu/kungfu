#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
  Solution() {
    for(int i = 1; i <= 26; i++)
      mp[i] = i - 1 + 'a';
  }

  void decodingsHelper(string& s, int index, string& sol, vector<string>& res) {
    if(index == s.size()) {
      res.push_back(sol);
      return;
    }

    int one_digit = s[index] - '0';
    sol.push_back(mp[one_digit]);
    decodingsHelper(s, index + 1, sol, res);
    sol.pop_back();

    if(index < s.size() - 1) {
      int two_digits = (s[index] - '0') * 10 + (s[index + 1] - '0');
      if(mp.count(two_digits) > 0) {
        sol.push_back(mp[two_digits]);
        decodingsHelper(s, index + 2, sol, res);
        sol.pop_back();
      }
    }
  }

  vector<string> decodings(string s){
    vector<string> res;
    int n = s.size();
    if(n == 0 || s[0] == '0')
      return res;

    string sol = "";
    decodingsHelper(s, 0, sol, res);
    return res;
  }
private:
  map<int, char> mp;
};

int main(){
  string str = "122628";
  Solution solution;
  vector<string> res = solution.decodings(str);
  for(int i = 0; i < res.size(); i++)
    cout << res[i] << endl;
  return 0;
}
