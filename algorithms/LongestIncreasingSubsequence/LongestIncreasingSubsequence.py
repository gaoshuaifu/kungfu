class Solution(object):
    def lengthOfLIS(self, nums):
        n = len(nums)
        if n == 0:
            return 0

        # dp[i] is the length of LIS up to ith postion and including nums[i]
        dp = [1] * n
        for i in range(1, n):
            prev_lengths = [dp[j] for j in range(i) if nums[j] < nums[i]]
            dp[i] = max(prev_lengths) + 1 if prev_lengths else 1
        return max(dp)
