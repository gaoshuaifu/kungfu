class Solution(object):
    def findDuplicates(self, nums):
        res = set()
        i = 0
        while i < len(nums):
            j = nums[i] - 1
            if i == j:
                i += 1
            elif nums[i] == nums[j]:
                res.add(nums[i])
                i += 1
            else:
                nums[i], nums[j] = nums[j], nums[i]
        return list(res)
