# A set of cyclic linkedlist, find the longest one.
class Solution(object):
    def arrayNesting(self, nums):
        visited = set()
        max_length = 0
        for i in range(len(nums)):
            length = 0
            num = nums[i]
            while num not in visited:
                length += 1
                visited.add(num)
                num = nums[num]
            max_length = max(max_length, length)
        return max_length
