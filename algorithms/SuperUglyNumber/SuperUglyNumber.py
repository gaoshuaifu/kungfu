class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        import sys
        dp = [sys.maxint] * n
        dp[0] = 1
        k = len(primes)
        index = [0] * k
        for i in range(1, n):
            for j in range(k):
                dp[i] = min(dp[i], dp[index[j]] * primes[j])
            for j in range(k):
                index[j] += (dp[i] == dp[index[j]] * primes[j])
        return dp[n - 1]
