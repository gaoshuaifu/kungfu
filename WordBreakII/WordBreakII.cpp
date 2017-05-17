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
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<vector<string> > dp(s.size());
        for(int i = s.size() - 1; i >= 0; i--){
            dp[i] = vector<string>();
            for(int j = i; j < s.size(); j++) {
                string word = s.substr(i, j - i + 1);
                if(wordDict.count(word) > 0) {
                    if(j == s.size() - 1)
                        dp[i].push_back(word);
                    else {
                        for(int k = 0; k < dp[j + 1].size(); k++){
                            dp[i].push_back(word + " " + dp[j + 1][k]);
                        }
                    }
                }
            }
        }
        return dp[0];
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
