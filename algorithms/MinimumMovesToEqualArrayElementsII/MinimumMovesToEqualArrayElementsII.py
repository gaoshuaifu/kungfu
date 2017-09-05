class Solution(object):
    def minMoves2(self, nums):
        median = sorted(nums)[len(nums) / 2]
        return sum(abs(num - median) for num in nums)
