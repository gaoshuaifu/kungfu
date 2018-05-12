class Solution(object):
    def findKthLargest(self, nums, k):
        from heapq import *
        heap = nums[:k]  # min heap
        heapify(heap)
        for num in nums[k:]:
            if num > min(heap):
                heappushpop(heap, num)   
        return min(heap)
