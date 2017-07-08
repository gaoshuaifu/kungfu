class Solution(object):
    def diameterOfBinaryTreeHelper(self, node):
        if not node:
            return 0, 0
        left_diameter, left_hight = self.diameterOfBinaryTreeHelper(node.left)
        right_diameter, right_hight = self.diameterOfBinaryTreeHelper(node.right)
        diameter = max(left_diameter, right_diameter, left_hight + right_hight)
        height = max(left_hight, right_hight) + 1
        return diameter, height

    def diameterOfBinaryTree(self, root):
        diameter, _ = self.diameterOfBinaryTreeHelper(root)
        return diameter
