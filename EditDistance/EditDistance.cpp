/*
 * time: O(m * n), space: O(min(m, n))
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/******************

l = "abcdef"
s = "ace"

dp[i][j] is the number of edit distance between word1[0..(i - 1)] and word2[0..(j - 1)]

    if(word1[i - 1] == word2[j - 1])
        dp[i][j] = dp[i - 1][j - 1];
    else
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
        
---------------
  |\0|a |c |e |
---------------
\0|  |  |  |  |
---------------
a |  |  |  |  |
---------------
b |  |  |  |  |
---------------
c |  |  |  |  |
---------------
d |  |  |  |  |
---------------
e |  |  |  |  |
---------------
f |  |  |  |  |
---------------

*******************/

class Solution{
public:
    int min3(int a, int b, int c){
        return min(min(a, b), c);
    }
    
    int minDistanceHelper(string l, string s){
        int m = l.size();
        int n = s.size();
        
        vector<int> curr(n + 1, 0);
        for(int j = 0; j <= n; j++)
            curr[j] = j;
        
        for(int i = 1; i <= m; i++){
            vector<int> next(n + 1, 0);
            next[0] = i;
            
            for(int j = 1; j <= n; j++){
                if(l[i - 1] == s[j - 1])
                    next[j] = curr[j - 1];
                else
                    next[j] = min3(next[j - 1], curr[j], curr[j - 1]) + 1;
            }
            curr = next;
        }
        return curr[n];
    }
    
    int minDistance(string word1, string word2){
        if(word1.size() > word2.size())
            return minDistanceHelper(word1, word2);
        else
            return minDistanceHelper(word2, word1);
    }
};

class Solution1{
public:
    int min3(int a, int b, int c){
        return min(min(a, b), c);
    }
    
    int minDistance(string word1, string word2){
        int m = word1.size();
        int n = word2.size();
    
        int dp[m + 1][n + 1];   
        dp[0][0] = 0;
        
        for(int j = 1; j <= n; j++)
            dp[0][j] = j;
        
        for(int i = 1; i <= m; i++)
            dp[i][0] = i;
            
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j] = min3(dp[i][j - 1] + 1,
                                dp[i - 1][j] + 1,
                                dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]));
        
        return dp[m][n];
    }
};

int main(){
    Solution solution;
    cout << solution.minDistance("abcdef", "ace") << endl;
    return 0;
}
