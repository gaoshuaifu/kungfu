#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool wordBreak(string s, unordered_set<string>& wordDict) {
    int n = s.size();

    // dp[i] represents that substring from 0 to i can be broken or not
    bool dp[n] = {false};

    for(int i = 0; i < n; i++) {
      string word = s.substr(0, i + 1);

      // Check if the substring from 0 to i is in dict or not
      if(wordDict.count(word) > 0) {
        dp[i] = true;
        continue;
      }

      // If not, break the substring and check
      for(int j = 0 ; j < i; j++) {
        if(dp[j]) {
          string leftWord = s.substr(j + 1, i - j);
          if(wordDict.count(leftWord) > 0) {
            dp[i] = true;
            break;
          }
        }
      }
    }
    return dp[n - 1];
  }
};

class Solution1 {
public:
  bool wordBreakHelper(string& s, unordered_set<string>& wordDictint, int start) {
    if(start == s.size())
      return true;

    for(int end = start; end < s.size(); end++) {
      string word = s.substr(start, end - start + 1);
      if(wordDictint.count(word) > 0 && wordBreakHelper(s, wordDictint, end + 1))
        return true;
    }
    return false;
  }

  bool wordBreak(string s, unordered_set<string>& wordDict) {
    return wordBreakHelper(s, wordDict, 0);
  }
};
