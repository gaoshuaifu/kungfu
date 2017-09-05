class Solution(object):
    def findLHS(self, nums):
        from collections import Counter
        c1 = Counter(nums)
        c2 = Counter([num + 1 for num in nums])
        res = 0
        for k in c1.keys():
            if k in c2:
                res = max(res, c1[k] + c2[k])
        return res
