class Solution(object):
    def subsets(self, nums):
        res = [[]]
        for num in nums:
            s = len(res)
            for i in range(s):
                res.append(res[i] + [num])
        return res
