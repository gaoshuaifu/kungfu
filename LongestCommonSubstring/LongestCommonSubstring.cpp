#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int longestCommonSubstringLen(string s1, string s2){
    if(s1.size() < s2.size())
      swap(s1, s2);

    int m = s1.size();
    int n = s2.size();

    int maxLen = 0;

    vector<int> curr(n + 1, 0);
    for(int j = 0; j <= n; j++)
      curr[j] = 0;

    for(int i = 1; i <= m; i++){
      vector<int> next(n + 1, 0);
      next[0] = 0;
      for(int j = 1; j <= n; j++){
        if(s1[i - 1] == s2[j - 1])
          next[j] = curr[j - 1] + 1;
        else
          next[j] = 0;

        maxLen = max(maxLen, next[j]);
      }
      curr = next;
    }

    return maxLen;
  }
};

int main(){
  string s1 = "abcbdab";
  string s2 = "bdcaba";

  Solution solution;
  int len = solution.longestCommonSubstringLen(s1, s2);
  cout << len << "\n";

  return 0;
}
