import copy
class Solution(object):
    def permuteHelper(self, nums, index):
        if index == len(nums):
            self.res.append(copy.deepcopy(nums))
            return
        
        for i in range(index, len(nums)):
            nums[index], nums[i] = nums[i], nums[index]
            self.permuteHelper(nums, index + 1)
            nums[index], nums[i] = nums[i], nums[index]
            
    def permute(self, nums):
        self.res = []
        self.permuteHelper(nums, 0)
        return self.res
