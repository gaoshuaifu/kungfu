class Solution(object):
    def findPairs(self, nums, k):
        if k > 0:
            return len(set(nums) & set(num + k for num in nums))
        elif k==0:
            return len([v for v in collections.Counter(nums).values() if v > 1])
        else:
            return 0
