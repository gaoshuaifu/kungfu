class Solution(object):
    def _merge(self, left, right):
        i, j = 0, 0
        nums = []
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                nums.append(left[i])
                i += 1
            else:
                nums.append(right[j])
                j += 1

        if i < len(left):
            nums.extend(left[i:])
        else:
            nums.extend(right[j:])

        return nums

    def merge_sort(self, nums):
        n = len(nums)
        if n <= 1:
            return nums

        mid = n / 2
        left = nums[:mid]
        right = nums[mid:]

        left = self.merge_sort(left)
        right = self.merge_sort(right)
    
        nums = self._merge(left, right)
        return nums


s = Solution()
print(s.merge_sort([3, 5, 1, 4, 2]))
