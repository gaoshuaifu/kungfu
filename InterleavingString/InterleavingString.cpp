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
t = "aabccdeef"

dp[i][j] is whether t[0..(i + j - 1)] is formed by the interleaving of s1[0..(i - 1)] and s2[0..(j - 1)]
    dp[i][j] = (dp[i][j - 1] && (s1[j - 1] == s3[i + j - 1])) ||
                 (dp[i - 1][j] && (s2[i - 1] == s3[i + j - 1]));

---------------
    |\0|a |c |e |
---------------
\0|    |    |    |    |
---------------
a |    |    |    |    |
---------------
b |    |    |    |    |
---------------
c |    |    |    |    |
---------------
d |    |    |    |    |
---------------
e |    |    |    |    |
---------------
f |    |    |    |    |
---------------

*******************/

class Solution{
public:
    bool isInterleaveHelper(string l, string s, string t){
        int m = l.size();
        int n = s.size();

        vector<bool> curr(n + 1, false);
        curr[0] = true;
        for(int j = 1; j <= n; j++)
            curr[j] = curr[j - 1] && (s[j - 1] == t[j - 1]);

        for(int i = 1; i <= m; i++){
            vector<bool> next(n + 1, false);
            next[0] = curr[0] && (l[i - 1] == t[i - 1]);

            for(int j = 1; j <= n; j++)
                next[j] = (next[j - 1] && (s[j - 1] == t[i + j - 1])) || (curr[j] && (l[i - 1] == t[i + j - 1]));

            curr = next;
        }
        return curr[n];
    }

    bool isInterleave(string s1, string s2, string s3){
        if(s1.size() + s2.size() != s3.size())
            return false;

        if(s1.size() > s2.size())
            return isInterleaveHelper(s1, s2, s3);
        else
            return isInterleaveHelper(s2, s1, s3);
    }
};

class Solution1{
public:
    bool isInterleave(string s1, string s2, string s3){
        if(s1.size() + s2.size() != s3.size())
            return false;

        int m = s1.size();
        int n = s2.size();

        bool dp[m + 1][n + 1];
        dp[0][0] = true;

        for(int j = 1; j <= n; j++)
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);

        for(int i = 1; i <= m; i++)
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j] = (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1])) ||
                             (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]));

        return dp[m][n];
    }
};

int main(){
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";

    Solution solution;
    bool res = solution.isInterleave(s1, s2, s3);
    cout << res << endl;

    s3 = "aadbbbaccc";
    res = solution.isInterleave(s1, s2, s3);
    cout << res << endl;

    return 0;
}

