class TreeNode(object):
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

        # The number of numbers equal to the val of current node.
        self.cnt_equal = 1

        # The number of numbers less than the val of current node.
        self.cnt_less = 0

class Solution(object):
    def search(self, head, val):
        if not head:
            return 0
        if val == head.val:
            return head.cnt_less
        elif val < head.val:
            return self.search(head.left, val)
        else:
            return head.cnt_equal + head.cnt_less + self.search(head.right, val)

    def insert(self, head, val):
        if not head:
            return TreeNode(val)

        if val == head.val:
            head.cnt_equal += 1
        elif val < head.val:
            head.cnt_less += 1
            head.left = self.insert(head.left, val)
        else:
            head.right = self.insert(head.right, val)
        return head

    def countSmaller(self, nums):
        res = []
        head = None

        # Iterate numbers from right to left
        for num in nums[::-1]:
            res.append(self.search(head, num))
            head = self.insert(head, num)
        return res[::-1]
