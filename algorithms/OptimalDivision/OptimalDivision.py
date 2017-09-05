class Solution(object):
    def optimalDivision(self, nums):
        nums = map(str, nums)
        if len(nums) <= 2:
            return "/".join(nums)
        return "{}/({})".format(nums[0],  "/".join(nums[1:]))
