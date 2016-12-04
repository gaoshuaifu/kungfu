#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  string balance(string str) {
    int currentOpen = 0;
    int validOpen = 0;
    int excessClose = 0;

    for(int i = 0; i < str.size(); i++) {
      if(str[i] == '(')
        currentOpen++;
      else if(str[i] == ')'){
        if(currentOpen > 0) {
          currentOpen--;
          validOpen++;
        }
        else
          excessClose++;
      }
    }

    int j = 0;
    for(int i = 0; i < str.size(); i++) {
      if(str[i] == '(') {
        if(validOpen > 0)
          validOpen--;
        else
          continue;
      }
      if(str[i] == ')') {
        if(excessClose > 0) {
          excessClose--;
          continue;
        }
      }
      str[j++] = str[i];
    }
    str.erase(str.begin() + j, str.end());
    return str;
  }
};

class Solution1 {
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
