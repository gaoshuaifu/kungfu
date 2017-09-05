# Incrementing n - 1 smallest elements by 1 is essentially
# decreasing the largest element by 1
class Solution(object):
    def minMoves(self, nums):
        m = min(nums)
        return sum([num - m for num in nums])
