class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.stk = []
        self._reachLeftMost(root)

    def _reachLeftMost(self, node):
        while node:
            self.stk.append(node)
            node = node.left

    def hasNext(self):
        """
        :rtype: bool
        """
        return len(self.stk) > 0


    def next(self):
        """
        :rtype: int
        """
        node = self.stk.pop()
        if node.right:
            self._reachLeftMost(node.right)
        return node.val
