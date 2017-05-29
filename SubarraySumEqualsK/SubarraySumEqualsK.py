class Solution(object):
    def subarraySum(self, nums, k):
        from collections import defaultdict
        # The dict (value => the number of subarrays nums[0:i] whose sum equals to value)
        preSumCount = defaultdict(int)
        preSumCount[0] = 1
        res = 0
        s = 0
        for num in nums:
            s += num
            if(s - k in preSumCount):
                res += preSumCount[s - k]
            preSumCount[s] += 1
        return res
