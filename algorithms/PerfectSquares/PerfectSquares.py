class Solution(object):
    def _is_perfect_square(self, n):
        import math
        return math.sqrt(n) == int(math.sqrt(n))

    def numSquares(self, n):
        import sys
        dp = [sys.maxint] * (n + 1)
        dp[0] = 0
        for i in range(1, n + 1):
            if self._is_perfect_square(i):
                dp[i] = 1
            else:
                j = 1
                while i - j * j > 0:
                    dp[i] = min(dp[i], dp[i - j * j] + 1)
                    j += 1
        return dp[n]
