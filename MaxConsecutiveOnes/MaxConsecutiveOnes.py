class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        count = 0
        max_len = 0
        for num in nums:
            if num == 1:
                count += 1
                max_len = max(max_len, count)
            else:
                count = 0
        return max_len
