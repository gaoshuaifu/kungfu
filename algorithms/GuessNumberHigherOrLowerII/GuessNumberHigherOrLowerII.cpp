class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
        for(int j = 1; j <= n; j++) {
            for(int i = j - 1; i >= 1; i--) {
                dp[i][j] = numeric_limits<int>::max();
                for(int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
};
