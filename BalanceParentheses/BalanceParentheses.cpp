#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  string balance(string str) {
    vector<int> stk;

    for(int i = 0; i < str.size(); i++) {
      if(str[i] == '(')
        stk.push_back(i);
      else if (str[i] == ')') {
        if(stk.empty())
          stk.push_back(i);
        else if(str[stk.back()] == '(')
          stk.pop_back();
        else
          stk.push_back(i);
      }
    }

    for(int i = stk.size() - 1; i >= 0; i--) {
      str.erase(str.begin() + stk[i]);
    }
    return str;
  }
};

int main() {
  Solution solution;
  vector<string> strs;
  strs.push_back("()");
  strs.push_back("a(b)c)");
  strs.push_back(")(");
  strs.push_back("(((((");
  strs.push_back("(()()(");
  strs.push_back(")(())(");
  for(int i = 0; i < strs.size(); i++) {
    cout << strs[i] << " => " << solution.balance(strs[i]) << endl;
  }
  return 0;
}
