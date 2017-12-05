class Solution(object):
    def findMissingRanges(self, nums, lower, upper):
        nums = [lower - 1] + nums + [upper + 1]
        intervals, i = [], 0
        while i + 1 < len(nums):
            while i + 1 < len(nums) and (nums[i] == nums[i + 1] or nums[i] + 1 == nums[i + 1]):
                i += 1
            if i + 1 < len(nums):
                intervals.append((nums[i] + 1, nums[i + 1] - 1))
            i += 1
        return ["%s" % a if a == b else "%s->%s" % (a, b) for a, b in intervals]
