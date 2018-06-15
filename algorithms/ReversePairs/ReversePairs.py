class Solution(object):
    def _merge(self, left, right):
        # count reverse pairs between left and right
        count = 0
        i, j = 0, 0
        while i < len(left):
            while j < len(right) and left[i] > right[j] * 2:
                j += 1
            count += j
            i += 1

        # merge left and right into a single sorted list
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

        return count, nums


    def _mergesort_and_count(self, nums):
        n = len(nums)
        if n <= 1:
            return 0, nums

        mid = n / 2
        left, right = nums[:mid], nums[mid:]

        count_left, left = self._mergesort_and_count(left)
        count_right, right = self._mergesort_and_count(right)

        count_cross, nums = self._merge(left, right)

        return count_left + count_right + count_cross, nums


    def reversePairs(self, nums):
        count, _ = self._mergesort_and_count(nums)
        return count





class TreeNode(object):
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.cnt_ge = 1

class Solution1(object):
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

s = Solution()
print(s.reversePairs([2,4,3,5,1]))
