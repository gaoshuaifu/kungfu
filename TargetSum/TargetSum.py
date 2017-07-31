# Solution of brute force
class Solution1(object):
    def helper(self, nums, S, index):
        if index == len(nums):
            if S == 0:
                self.count += 1
            return

        self.helper(nums, S + nums[index], index + 1)
        self.helper(nums, S - nums[index], index + 1)

    def findTargetSumWays(self, nums, S):
        self.count = 0
        self.helper(nums, S, 0)
        return self.count


# Solution with memorization
class Solution(object):
    def helper(self, nums, S, index, cache):
        if (S, index) in cache:
            return cache[(S, index)]

        if index == len(nums):
            return 1 if S == 0 else 0

        neg = self.helper(nums, S + nums[index], index + 1, cache)
        pos = self.helper(nums, S - nums[index], index + 1, cache)
        cache[(S, index)] = neg + pos
        return neg + pos

    def findTargetSumWays(self, nums, S):
        cache = {}
        return self.helper(nums, S, 0, cache)
