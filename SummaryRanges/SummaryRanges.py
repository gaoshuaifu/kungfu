class Solution(object):
    def summaryRanges(self, nums):
        res = []
        n = len(nums)
        i = 0
        while i < n:
            j = i
            while j + 1 < n and nums[j + 1] - nums[j] == 1:
                j += 1
            if i != j:
                res.append("%s->%s" % (nums[i], nums[j]))
            else:
                res.append("%s" % nums[i])
            i = j + 1
        return res
