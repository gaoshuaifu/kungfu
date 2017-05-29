# Sort the array and pairs are (a0, a1), (a2, a3)...(a_2n-2, a_2n-1)
class Solution(object):
    def arrayPairSum(self, nums):
        nums = sorted(nums)
        n = len(nums) / 2
        return sum([nums[2 * i] for i in range(n)])
