#include <iostream>
using namespace std;

class Solution{
public:
  bool matchChar(const char* s, const char* p) {
    return *s == *p || (*s && *p == '.');
  }

  bool isMatch(const char* s, const char* p){
    if(*p == '\0')
      return (*s == '\0');

    if(*(p + 1) != '*')
      return matchChar(s, p) && isMatch(s + 1, p + 1);
    else
      return isMatch(s, p + 2) || (matchChar(s, p) && isMatch(s + 1, p));
  }
};


class Solution1{
public:
  bool matchChar(const char* s, const char* p) {
    return (*s == *p) || (*s && *p == '.');
  }

  bool isMatch(const char* s, const char* p){
    if(*p == '\0')
      return (*s == '\0');

    if(*(p + 1) != '*')
      return matchChar(s, p) && isMatch(s + 1, p + 1);

    while(matchChar(s, p)){
      if(isMatch(s, p + 2))
        return true;
      s++;
    }
    return isMatch(s, p + 2);
  }
};

int main(){
  Solution solution;
  cout << solution.isMatch("aa", "a") << endl;
  cout << solution.isMatch("aa", "aa") << endl;
  cout << solution.isMatch("aaa", "aa") << endl;
  cout << solution.isMatch("aa", "a*") << endl;
  cout << solution.isMatch("aa", ".*") << endl;
  cout << solution.isMatch("ab", ".*") << endl;
  cout << solution.isMatch("aab", "c*a*b") << endl;
  return 0;
}
