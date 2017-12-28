class Solution(object):
    def helper(self, root):
        if root is None:
            return True, 0, float('inf'), float('-inf'), 0

        l_is_bst, l_size, l_min_val, l_max_val, l_max_size = self.helper(root.left)
        r_is_bst, r_size, r_min_val, r_max_val, r_max_size = self.helper(root.right)

        is_bst = l_is_bst and r_is_bst and l_max_val < root.val < r_min_val
        size = l_size + 1 + r_size
        min_val = min(root.val, l_min_val, r_min_val)
        max_val = max(root.val, l_max_val, r_max_val)
        max_size = size if is_bst else max(l_max_size, r_max_size)

        return is_bst, size, min_val, max_val, max_size

    def largestBSTSubtree(self, root):
        _, _, _, _, max_size = self.helper(root)
        return max_size
