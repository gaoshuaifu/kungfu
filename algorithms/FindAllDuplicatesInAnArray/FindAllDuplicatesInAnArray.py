class Solution(object):
    def findDuplicates(self, nums):
        # 1 ≤ nums[i] ≤ n, so put nums[i] into index nums[i] - 1
        i = 0
        while i < len(nums):
            j = nums[i] - 1
            if nums[i] != nums[j]:
                nums[i], nums[j] = nums[j], nums[i]
            else:
                i += 1

        # Scan the array, if the number at index i is not i + 1, then the number is a duplicate
        res = []
        for i in range(len(nums)):
            if nums[i] != i + 1:
                res.append(nums[i])
        return res
