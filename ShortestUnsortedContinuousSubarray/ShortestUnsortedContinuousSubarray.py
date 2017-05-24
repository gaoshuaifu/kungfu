class Solution(object):
    def findUnsortedSubarray(self, nums):
        n = len(nums)
        start, end = None, None
        max_val, min_val = nums[0], nums[n - 1]
        for i in range(1, n):
            max_val = max(max_val, nums[i])
            if nums[i] < max_val:
                end = i

            min_val = min(min_val, nums[n - 1 - i])
            if nums[n - 1 - i] > min_val:
                start = n - 1 - i

        return 0 if start is None else end - start + 1

class Solution1(object):
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

        return 0 if start is None else end - start + 1
