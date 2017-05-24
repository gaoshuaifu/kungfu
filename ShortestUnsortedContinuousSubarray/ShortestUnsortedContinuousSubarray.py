class Solution(object):
    def findUnsortedSubarray(self, nums):
        import sys
        n = len(nums)

        min_val = sys.maxint
        for i in range(1, n):
            if nums[i - 1] > nums[i] and min_val > nums[i]:
                min_val = nums[i]

        start = None
        for i in range(n):
            if nums[i] > min_val:
                start = i
                break

        max_val = -sys.maxint
        for i in range(n - 2, -1, -1):
            if nums[i] > nums[i + 1] and max_val < nums[i]:
                max_val = nums[i]

        end = None
        for i in range(n - 1, -1, -1):
            if nums[i] < max_val:
                end = i
                break

        if start is None:
            return 0

        return end - start + 1
