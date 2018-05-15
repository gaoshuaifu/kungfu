class Solution(object):
    def robHelper(self, root):
        if not root:
            return 0, 0

        leftRobbed, leftNotRobbed = self.robHelper(root.left)
        rightRobbed, rightNotRobbed = self.robHelper(root.right)

        return (
            root.val + leftNotRobbed + rightNotRobbed,
            max(leftRobbed, leftNotRobbed) + max(rightRobbed, rightNotRobbed),
        )

    def rob(self, root):
        rootRobbed, rootNotRobbed = self.robHelper(root)
        return max(rootRobbed, rootNotRobbed)
