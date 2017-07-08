class Solution(object):
    def getHeight(self, root):
        if not root: return 0
        return max(self.getHeight(root.left), self.getHeight(root.right)) + 1

    def findBottomLeftValueHelper(self, root, h):
        if not root: return None

        if h == 1: return root

        left = self.findBottomLeftValueHelper(root.left, h - 1)
        if left: return left

        right = self.findBottomLeftValueHelper(root.right, h - 1)
        if right: return right

    def findBottomLeftValue(self, root):
        h = self.getHeight(root)
        node = self.findBottomLeftValueHelper(root, h)
        return node.val
