class Solution(object):
    def threeSumSmaller(self, nums, target):
        n = len(nums)
        nums.sort()
        count = 0
        for i in range(n - 2):
            j, k = i + 1, n - 1
            while j < k:
                if nums[i] + nums[j] + nums[k] < target:
                    count += k - j
                    j += 1
                else:
                    k -= 1
        return count
