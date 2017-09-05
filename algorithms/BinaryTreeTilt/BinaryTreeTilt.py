class Solution(object):
    def findTiltHelper(self, node):
        if not node:
            return 0, 0

        left_tilt, left_sum = self.findTiltHelper(node.left)
        right_tilt, right_sum = self.findTiltHelper(node.right)

        tree_tilt = left_tilt + right_tilt + abs(left_sum - right_sum)
        tree_sum = left_sum + right_sum + node.val

        return tree_tilt, tree_sum

    def findTilt(self, root):
        tree_tilt, _ = self.findTiltHelper(root)
        return tree_tilt
