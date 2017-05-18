class Solution(object):
    def missingNumber(self, nums):
        n = len(nums)
        return n * (n + 1) / 2 - sum(nums)

# If nums is sorted, should use binary search
class Solution1(object):
    def missingNumber(self, nums):
        nums = sorted(nums)
        low, high = 0, len(nums)
        while low < high:
            mid = (low + high) / 2
            if nums[mid] == mid:
                low = mid + 1
            else:  # if nums[mid] > mid
                high = mid
        return low
