class Solution(object):
    def integerBreak(self, n):
        dp = [0] * (n + 1)
        for i in range(2, n + 1):
            dp[i] = max(
                [
                    max(dp[j], j) * max(dp[i - j], i - j)
                    for j in range(1, i / 2 + 1)
                ]
            )
        return dp[n]
