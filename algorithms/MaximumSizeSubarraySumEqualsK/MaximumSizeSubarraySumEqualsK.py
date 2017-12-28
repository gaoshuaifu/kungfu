class Solution(object):
    def maxSubArrayLen(self, nums, k):
        d = {}
        curr_sum, max_len = 0, 0

        for i in range(len(nums)):
            curr_sum += nums[i]
            if curr_sum == k:
                max_len = i + 1
            elif (curr_sum - k) in d:
                max_len = max(max_len, i - d[curr_sum - k])

            if curr_sum not in d:
                d[curr_sum] = i

        return max_len
