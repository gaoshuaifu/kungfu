class Solution(object):
    def matrixReshape(self, nums, r, c):
        if (len(nums) == r and len(nums[0]) == c) or (len(nums) * len(nums[0]) != r * c):
            return nums
        if c == 0:
            return [] * r

        res = []
        sub = []
        for row in nums:
            for num in row:
                sub.append(num)
                if len(sub) == c:
                    res.append(sub)
                    sub = []
        return res
