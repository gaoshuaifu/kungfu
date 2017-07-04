class Solution(object):
    def _getHeight(self, root):
        if root is None:
            return 0
        return self._getHeight(root.left) + 1

    def countNodes(self, root):
        if root is None:
            return 0
        l = self._getHeight(root.left)
        r = self._getHeight(root.right)

        if l == r:
            # root + complete left + right, 1 + (2 ** l - 1) + # of right
            return 2 ** l + self.countNodes(root.right)
        else:
            # root + complete right + left, 1 + (2 ** r - 1) + # of left
            return 2 ** r + self.countNodes(root.left)
