class Solution(object):
    def rob(self, nums):
        n = len(nums)
        if n == 0: return 0
        if n == 1: return nums[0]
        dp = [0] * 3
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])
        for i in range(2, n):
            dp[i % 3] = max(dp[(i - 2) % 3] + nums[i], dp[(i - 1) % 3]);
        return dp[(n - 1) % 3]
