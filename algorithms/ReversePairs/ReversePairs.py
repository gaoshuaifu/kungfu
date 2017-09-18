class TreeNode(object):
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.cnt_ge = 1

class Solution(object):
    def _insert(self, head, val):
        if not head:
            return TreeNode(val)

        if val == head.val:
            head.cnt_ge += 1
        elif val < head.val:
            head.left = self._insert(head.left, val)
        else:
            head.cnt_ge += 1
            head.right = self._insert(head.right, val)
        return head

    def _search(self, head, val):
        if not head:
            return 0

        if val == head.val:
            return head.cnt_ge
        elif val < head.val:
            return head.cnt_ge + self._search(head.left, val)
        else:
            return self._search(head.right, val)

    def reversePairs(self, nums):
        count, head = 0, None
        for num in nums:
            count += self._search(head, num * 2 + 1)
            head = self._insert(head, num)
        return count

class Solution(object):
    def _mergesort_and_count(self, nums, low, high):
        if low >= high:
            return 0

        count = 0
        mid = (low + high) / 2
        count += self._mergesort_and_count(nums, low, mid)
        count += self._mergesort_and_count(nums, mid + 1, high)

        i = low
        j = mid + 1
        while i <= mid:
            while j <= high and nums[i] > nums[j] * 2:
                j += 1
            count += j - (mid + 1)
            i += 1

        nums[low: high + 1] = sorted(nums[low: high + 1])
        return count

    def reversePairs(self, nums):
        return self._mergesort_and_count(nums, 0, len(nums) - 1)
