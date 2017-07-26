class Solution(object):
    def smallestRange(self, nums):
        import sys, heapq
        heap = [(num[0], i, 0) for i, num in enumerate(nums)]
        heapq.heapify(heap)
        right = max(heap)[0]
        res = [-sys.maxint, sys.maxint]
        while True:
            left, i, j = heapq.heappop(heap)
            if right - left < res[1] - res[0]:
                res = [left, right]
            if j + 1 == len(nums[i]):
                break
            v = nums[i][j+1]
            heapq.heappush(heap, (v, i, j + 1))
            right = max(right, v)
        return res

class Solution(object):
    def smallestRange(self, nums):
        import sys
        indices = [0] * len(nums)
        res = [-sys.maxint, sys.maxint]
        while True:
            values = [array[i] for array, i in zip(nums, indices)]
            left, right = min(values), max(values)
            if right - left < res[1] - res[0]:
                res = [left, right]
            min_index = values.index(left)
            indices[min_index] += 1
            if indices[min_index] == len(nums[min_index]):
                break
        return res
