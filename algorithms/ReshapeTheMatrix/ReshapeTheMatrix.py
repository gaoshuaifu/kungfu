class Solution(object):
    def matrixReshape(self, nums, r, c):
        if len(nums) * len(nums[0]) != r * c:
            return nums
        res, sub = [], []
        for row in nums:
            for num in row:
                sub.append(num)
                if len(sub) == c:
                    res.append(sub)
                    sub = []
        return res
