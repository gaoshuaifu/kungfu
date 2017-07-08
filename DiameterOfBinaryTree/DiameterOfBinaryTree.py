class Solution(object):
    def diameterOfBinaryTreeHelper(self, node):
        if not node:
            return 0, 0

        left_diameter, left_hight = self.diameterOfBinaryTreeHelper(node.left)
        right_diameter, right_hight = self.diameterOfBinaryTreeHelper(node.right)

        return (
            max(left_diameter, right_diameter, left_hight + right_hight),
            max(left_hight, right_hight) + 1
        )

    def diameterOfBinaryTree(self, root):
        diameter, height = self.diameterOfBinaryTreeHelper(root)
        return diameter
