class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        d = {}
        for i in range(len(nums)):
            if nums[i] in d and i - d[nums[i]] <= k:
                return True
            d[nums[i]] = i
        return False

class Solution1(object):
    def containsNearbyDuplicate(self, nums, k):
        s = set()
        for i in range(len(nums)):
            if i > k:
                s.remove(nums[i - k - 1])
            if nums[i] in s:
                return True
            s.add(nums[i])
        return False
