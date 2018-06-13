class Solution(object):
    def subsets(self, nums):
        res = [[]]
        for num in nums:
            s = len(res)
            for i in range(s):
                res.append(res[i] + [num])
        return res


import copy
class Solution(object):
    def subsetsHelper(self, nums, start):
        self.res.append(copy.deepcopy(self.sol))
        for i in range(start, len(nums)):
            self.sol.append(nums[i])
            self.subsetsHelper(nums, i + 1)
            self.sol.pop()

    def subsets(self, nums):
        self.sol, self.res = [], []
        self.subsetsHelper(nums, 0)
        return self.res
