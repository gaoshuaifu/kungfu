#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
  bool isWord(map<string, int>& mp, string& word) {
    return mp.count(word) > 0;
  }

  bool isPalindrom(string& word) {
    int i = 0;
    int j = word.size() - 1;
    while(i <= j) {
      if(word[i++] != word[j--])
        return false;
    }
    return true;
  }

  vector<vector<int> > palindromePairs(vector<string>& words) {
    vector<vector<int> > res;

    map<string, int> mp;
    for(int i = 0; i < words.size(); i++) {
      mp[words[i]] = i;
    }
    for(int i = 0; i < words.size(); i++) {
      string word = words[i];
      for(int j = 0; j < word.size(); j++) {
        string left = word.substr(0, j);
        string right = word.substr(j, word.size() - j);
        string rleft = word.substr(0, j);
        string rright = word.substr(j, word.size() - j);
        reverse(rleft.begin(), rleft.end());
        reverse(rright.begin(), rright.end());

        if(isWord(mp, rleft) && isPalindrom(right)) {
          int left_index = mp[word];
          int right_index = mp[rleft];
          if(left_index != right_index) {
            vector<int> sol;
            sol.push_back(left_index);
            sol.push_back(right_index);
            res.push_back(sol);
          }
        }
        if(isWord(mp, rright) && isPalindrom(left)) {
          int left_index = mp[rright];
          int right_index = mp[word];
          if(left_index != right_index) {
            vector<int> sol;
            sol.push_back(left_index);
            sol.push_back(right_index);
            res.push_back(sol);
          }
        }
      }
    }
    return res;
  }
};

int main() {
  vector<string> words;
  words.push_back("abcd");
  words.push_back("dcba");
  words.push_back("lls");
  words.push_back("s");
  words.push_back("sssll");

  vector<vector<int> > res;
  Solution solution;
  res = solution.palindromePairs(words);
  for(int i = 0; i < res.size(); i++)
    cout << words[res[i][0]] << " " << words[res[i][1]] << endl;
  return 0;
}
