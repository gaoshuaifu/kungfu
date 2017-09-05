class Solution(object):
    def maximumProduct(self, nums):
        import heapq
        large3 = heapq.nlargest(3, nums)
        small2 = heapq.nsmallest(2, nums)
        return max(
            large3[0] * large3[1] * large3[2],
            small2[0] * small2[1] * large3[0],
        )
