/*
 * time: O(n), space: O(1)
 */

#include <iostream>
#include <stack>
using namespace std;

class Solution{
public:
  bool isValid(string s){
    int n = s.size();
    if(n % 2) return false;

    stack<char> stk;
    for(int i = 0; i < n; i++){
      char c = s[i];
      if(stk.empty()){
        if(c == ')' || c == ']' || c == '}')
          return false;
        else
          stk.push(c);
      }
      else if(stk.top() == '{' && s[i] == '}' || stk.top() == '[' && s[i] == ']' || stk.top() == '(' && s[i] == ')')
        stk.pop();
      else
        stk.push(c);
    }

    return stk.empty();
  }
};

int main(){
  string s = "]";
  Solution solution;
  cout << solution.isValid(s) << endl;
  return 0;
}

