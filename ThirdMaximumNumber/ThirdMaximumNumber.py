class Solution(object):
    def thirdMax(self, nums):
        s = set()
        for num in nums:
            s.add(num)
            if len(s) > 3:
                s.discard(min(s))
        return min(s) if len(s) == 3 else max(s)
