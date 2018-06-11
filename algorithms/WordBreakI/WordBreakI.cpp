#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.size();

        // dp[i] represents that substring from 0 to i can be broken or not
        bool dp[n] = {false};

        for(int i = 0; i < n; i++) {
            string word = s.substr(0, i + 1);

            // Check if the substring from 0 to i is in dict or not
            if(wordSet.count(word) > 0) {
                dp[i] = true;
                continue;
            }

            // If not, break the substring and check
            for(int j = 0 ; j < i; j++) {
                if(dp[j]) {
                    string right = s.substr(j + 1, i - j);
                    if(wordSet.count(right) > 0) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n - 1];
    }
};
