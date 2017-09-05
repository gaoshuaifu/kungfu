class Solution(object):
    def nthUglyNumber(self, n):
        dp = [1] * n
        i2, i3, i5 = 0, 0, 0
        for i in range(1, n):
            dp[i] = min(dp[i2] * 2, dp[i3] * 3, dp[i5] * 5)
            if dp[i] == dp[i2] * 2:
                i2 += 1
            if dp[i] == dp[i3] * 3:
                i3 += 1
            if dp[i] == dp[i5] * 5:
                i5 += 1
        return dp[n - 1]
