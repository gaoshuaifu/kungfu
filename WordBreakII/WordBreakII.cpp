#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> wordBreakHelper(string s, unordered_set<string>& wordDict, unordered_map<string, vector<string> >& cache) {
    if(cache.count(s) > 0)
      return cache[s];

    vector<string> res;
    if(wordDict.count(s) > 0)
      res.push_back(s);

    for(int i = 0; i < s.size(); i++) {
      string left = s.substr(0, i + 1);
      if(wordDict.count(left) > 0) {
        string right = s.substr(i + 1, s.size() - i - 1);
        vector<string> resRight = wordBreakHelper(right, wordDict, cache);
        for(int j = 0; j < resRight.size(); j++) {
          res.push_back(left + " " + resRight[j]);
        }
      }
    }
    cache[s] = res;
    return res;
  }

  vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    unordered_map<string, vector<string> > cache;
    vector<string> res = wordBreakHelper(s, wordDict, cache);
    return res;
  }
};

class Solution1 {
public:
  void wordBreakHelper(string& s, unordered_set<string>& wordDict, int start, string sol, vector<string>& res) {
    if(start == s.size()) {
      res.push_back(sol);
      return;
    }

    for(int end = start; end < s.size(); end++) {
      string word = s.substr(start, end - start + 1);
      if(wordDict.count(word) > 0) {
        string str = sol;
        if(start > 0)
          str += " ";
        str += word;
        wordBreakHelper(s, wordDict, end + 1, str, res);
      }
    }
  }

  vector<string> wordBreak(string s, unordered_set<string>& wordDict) {

    vector<string> res;
    wordBreakHelper(s, wordDict, 0, "", res);
    return res;
  }
};


int main() {
  string s = "catsanddog";
  unordered_set<string> wordDict;
  wordDict.insert("cat");
  wordDict.insert("cats");
  wordDict.insert("and");
  wordDict.insert("sand");
  wordDict.insert("dog");

  Solution solution;
  vector<string> res = solution.wordBreak(s, wordDict);
  for(int i = 0; i < res.size(); i++)
    cout << res[i] << endl;
  return 0;
}
