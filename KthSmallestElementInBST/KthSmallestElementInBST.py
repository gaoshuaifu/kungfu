class Solution(object):
    def _getSize(self, root):
        if root is None:
            return 0
        return 1 + self._getSize(root.left) + self._getSize(root.right)

    def kthSmallest(self, root, k):
        l = self._getSize(root.left)
        if k <= l:
            return self.kthSmallest(root.left, k)
        elif k == l + 1:
            return root.val
        else:
            return self.kthSmallest(root.right, k - l - 1)
