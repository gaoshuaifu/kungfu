class Solution(object):
    def dfs(self, nums, targets, index):
        if index == len(nums):
            return True

        for i in range(4):
            if targets[i] >= nums[index]:
                targets[i] -= nums[index]
                if self.dfs(nums, targets, index + 1):
                    return True
                targets[i] +=  nums[index]
        return False

    def makesquare(self, nums):
        if len(nums) < 4:
            return False

        nums_sum = sum(nums)
        if nums_sum % 4 != 0:
            eturn False

        target = nums_sum / 4
        nums.sort(reverse=True)

        targets = [target] * 4

        return self.dfs(nums, targets, 0)
