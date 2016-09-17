/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <string>
#include <map>
#include <climits>
using namespace std;

class Solution{
public:
  string minWindow(string S, string T){
    int minLen = INT_MAX;
    string minStr = "";

    int needFind[256] = {0};
    int hasFound[256] = {0};
    for(int i = 0; i < T.size(); i++)
      needFind[T[i]]++;

    int start = 0;
    int end = 0;
    int count = 0;
    while(end < S.size()){
      if(needFind[S[end]] == 0){
        end++;
        continue;
      }

      if(hasFound[S[end]] < needFind[S[end]])
        count++;
      hasFound[S[end]]++;

      if(count < T.size()){
        end++;
        continue;
      }

      while(needFind[S[start]] == 0 || hasFound[S[start]] > needFind[S[start]]){
        if(hasFound[S[start]] > needFind[S[start]])
          hasFound[S[start]]--;
        start++;
      }
      int len = end - start + 1;
      if(len < minLen){
        minLen = len;
        minStr = S.substr(start, minLen);
      }

      end++;
    }

    return minStr;
  }
};


class Solution1{
public:
  string minWindow(string S, string T){
    string minStr = "";
    int minLen = INT_MAX;

    int needFind[256] = {0};
    int hasFound[256] = {0};
    for(int i = 0; i < T.size(); i++)
      needFind[T[i]]++;

    int start = 0;
    int end = 0;
    int count = 0;
    while(end < S.size()){
      if(hasFound[S[end]] < needFind[S[end]])
        count++;
      hasFound[S[end]]++;

      if(count < T.size()){
        end++;
        continue;
      }

      while(hasFound[S[start]] > needFind[S[start]]){
        hasFound[S[start]]--;
        start++;
      }
      int len = end - start + 1;
      if(len < minLen){
        minLen = len;
        minStr = S.substr(start, len);
      }
      end++;
    }
    return minStr;
  }
};

int main(){
  string S = "ADOBECODEBANC";
  string T = "ABC";

  Solution solution;
  string res = solution.minWindow(S, T);
  cout << res << endl;

  return 0;
}
