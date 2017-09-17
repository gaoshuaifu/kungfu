class Solution(object):
    def __init__(self, nums):
        self.nums = nums

    def pick(self, target):
        import random
        res, count = None, 0
        for i in range(len(self.nums)):
            if self.nums[i] == target:
                r = random.randint(0, count)
                if r == 0:
                    res = i
                count += 1
        return res
