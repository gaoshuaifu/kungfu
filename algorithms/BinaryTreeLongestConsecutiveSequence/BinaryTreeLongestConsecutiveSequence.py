class Solution(object):
    def helper(self, root):
        if not root:
            return 0, 0

        left_longest, left_consecutive = self.helper(root.left)
        right_longest, right_consecutive = self.helper(root.right)

        if not root.left or root.val + 1 == root.left.val:
            left_consecutive += 1
        else:
            left_consecutive = 1

        if not root.right or root.val + 1 == root.right.val:
            right_consecutive += 1
        else:
            right_consecutive = 1

        consecutive = max(left_consecutive, right_consecutive)

        return max(left_longest, right_longest, consecutive), consecutive

    def longestConsecutive(self, root):
        longest, _ = self.helper(root)
        return longest
