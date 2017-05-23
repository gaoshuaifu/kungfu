class Solution(object):
    def arrayPairSum(self, nums):
        nums = sorted(nums)
        n = len(nums) / 2
        return sum([nums[2 * i] for i in range(n)])
