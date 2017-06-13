class Solution(object):
    def triangleNumber(self, nums):
        n = len(nums)
        nums = sorted(nums)
        count = 0

        # k iterates from n - 1 to 2
        for k in reversed(range(2, n)):
            i, j = 0, k - 1
            while i < j:
                if nums[i] + nums[j] > nums[k]:
                    count += (j - i)
                    j -= 1
                else:
                    i += 1
        return count
