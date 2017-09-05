/*
 * time: O(m * n), space: O(min(m, n))
 */
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

/******************

S = "aabbcc"
T = "abc"

dp[i][j] is the number of subsequences of S[0..(i - 1)] equivalent to T[0..(j - 1)];

    if(S[i - 1] == T[j - 1])
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    else
        dp[i][j] = dp[i - 1][j];
OR
    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * (S[i - 1] == T[j - 1]);

---------------
    |\0|a |b |c |
---------------
\0|    |    |    |    |
---------------
a |    |    |    |    |
---------------
a |    |    |    |    |
---------------
b |    |    |    |    |
---------------
b |    |    |    |    |
---------------
c |    |    |    |    |
---------------
c |    |    |    |    |
---------------

*******************/

class Solution{
public:
    int numDistinct(string S, string T){
        int m = S.size();
        int n = T.size();

        vector<int> curr(n + 1, 0);
        curr[0] = 1;
        for(int j = 1; j <= n; j++)
            curr[j] = 0;

        for(int i = 1; i <= m; i++){
            vector<int> next(n + 1, 0);
            next[0] = 1;

            for(int j = 1; j <= n; j++)
                next[j] = curr[j] + curr[j - 1] * (S[i - 1] == T[j - 1]);

            curr = next;
        }
        return curr[n];
    }
};

class Solution1{
public:
    int numDistinct(string S, string T){
        int m = S.size();
        int n = T.size();

        int dp[m + 1][n + 1];
        dp[0][0] = 1;

        for(int j = 1; j <= n; j++)
            dp[0][j] = 0;

        for(int i = 1; i <= m; i++)
            dp[i][0] = 1;

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * (S[i - 1] == T[j - 1]);

        return dp[m][n];
    }
};

int main(){
    string S = "aabbcc";
    string T = "abc";

    Solution1 solution;
    cout << solution.numDistinct(S, T) << endl;

    return 0;
}
