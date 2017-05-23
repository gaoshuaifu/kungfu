class Solution(object):
    def subarraySum(self, nums, k):
        from collections import defaultdict

        preSumCount = defaultdict(int)
        preSumCount[0] = 1
        res = 0
        sum = 0
        for num in nums:
            sum += num
            if(sum - k in preSumCount):
                res += preSumCount[sum - k]
            preSumCount[sum] += 1
        return res
