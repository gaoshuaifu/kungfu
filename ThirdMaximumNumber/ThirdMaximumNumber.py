class Solution(object):
    def thirdMax(self, nums):
        n = len(nums)
        i = 0
        heap = []
        while i < n and len(heap) < 3:
            if nums[i] not in heap:
                heap.append(nums[i])
            i += 1

        if len(heap) == 1:
            return heap[0]
        if len(heap) == 2:
            return max(heap)

        heap.sort(reverse=True)

        while i < n:
            if nums[i] not in heap:
                if nums[i] > heap[-1]:
                    heap.pop()
                    heap.append(nums[i])
                    heap.sort(reverse=True)
            i += 1

        return heap[-1]
