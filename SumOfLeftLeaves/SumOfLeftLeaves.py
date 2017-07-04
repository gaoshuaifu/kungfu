class Solution(object):
    def _sumOfLeftLeavesHelper(self, root, is_left=False):
        if not root:
            return 0

        if not root.left and not root.right:
            return root.val if is_left else 0

        left = self._sumOfLeftLeavesHelper(root.left, is_left=True)
        right = self._sumOfLeftLeavesHelper(root.right, is_left=False)
        return left + right

    def sumOfLeftLeaves(self, root):
        return self._sumOfLeftLeavesHelper(root)
