# Scan the array from left to right and keep track of max value so far.
# If the current number is not the max value, it should be included in the subarray to sort.
# Scan the array from right to left and keep track of min value so far.
# If the current number is not the min value, it should be included in the subarray to sort.
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
