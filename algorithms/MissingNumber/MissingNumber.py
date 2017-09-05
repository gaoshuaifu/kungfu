class Solution(object):
    def missingNumber(self, nums):
        n = len(nums)
        return n * (n + 1) / 2 - sum(nums)

# a^b^b = a
class Solution1(object):
    def missingNumber(self, nums):
        res = 0
        n = len(nums)
        for i in range(n):
            res ^= i ^ nums[i]
        res ^= n
        return res

"""
When nums is sorted, the missing number splits the array to two parts.
On left i == nums[i], and on right i < nums[i].

During the binary search, low and high move tarwards boundary and eventually meet.

In the second last step, low is at the right most of the left part and high is at the
left most of the right part. In this case, high - low = 1 and mid = low.

In the last step, low moves right low = mid + 1, so low == high,
and low and high are both the missing number.
"""
class Solution2(object):
    def missingNumber(self, nums):
        nums = sorted(nums)
        low, high = 0, len(nums)
        while low < high:
            mid = (low + high) / 2
            if nums[mid] == mid:
                low = mid + 1
            else:  # nums[mid] > mid
                high = mid
        return low
