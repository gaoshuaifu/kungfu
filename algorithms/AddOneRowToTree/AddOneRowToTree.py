class Solution(object):
    def addOneRow(self, root, v, d):
        if not root:
            return None

        if d == 1:
            node = TreeNode(v)
            node.left = root
            return node
        elif d == 2:
            left_node = TreeNode(v)
            left_node.left = root.left
            root.left = left_node
            right_node = TreeNode(v)
            right_node.right = root.right
            root.right = right_node
        else:
            root.left = self.addOneRow(root.left, v, d - 1)
            root.right = self.addOneRow(root.right, v, d - 1)

        return root
