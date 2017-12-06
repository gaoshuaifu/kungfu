class Solution(object):
    def equal(self, node1, node2):
        return node1 is None or node2 is None or node1.val == node2.val

    def helper(self, root):
        if root is None:
            return True, 0

        left_is_unival, left_cnt = self.helper(root.left)
        right_is_unival, right_cnt = self.helper(root.right)

        curr_is_unival = (
            left_is_unival and right_is_unival and
            self.equal(root, root.left) and self.equal(root, root.right)
        )
        curr_cnt = left_cnt + right_cnt + (1 if curr_is_unival else 0)

        return curr_is_unival, curr_cnt

    def countUnivalSubtrees(self, root):
        _, cnt = self.helper(root)
        return cnt
