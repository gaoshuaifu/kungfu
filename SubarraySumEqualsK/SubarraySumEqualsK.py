class Solution(object):
    def subarraySum(self, nums, k):
        from collections import defaultdict

        d = defaultdict(int)
        d[0] = 1

        res = 0
        s = 0
        for num in nums:
            s += num
            if(s - k in d):
                res += d[s - k]
            d[s] += 1
        return res
