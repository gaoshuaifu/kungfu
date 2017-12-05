class Solution(object):
    def upsideDownBinaryTree(self, root):
        if root is None or (root.left is None and root.right is None):
            return root

        new_root = self.upsideDownBinaryTree(root.left)
        root.left.left = root.right
        root.left.right = root
        root.left = None
        root.right = None
        return new_root
