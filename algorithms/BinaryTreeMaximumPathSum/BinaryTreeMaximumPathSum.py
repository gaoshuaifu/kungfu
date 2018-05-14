import sys
class Solution(object):
    def maxPathSumHelper(self, root):
        if not root:
            return -sys.maxint, 0
        left_max_path_sum, left_path_sum = self.maxPathSumHelper(root.left)
        right_max_path_sum, right_path_sum = self.maxPathSumHelper(root.right)
        return (
            max(left_max_path_sum, right_max_path_sum, left_path_sum + right_path_sum + root.val), 
            max(left_path_sum + root.val, right_path_sum + root.val, 0)   
        )
        
    def maxPathSum(self, root):
        max_path_sum, _ = self.maxPathSumHelper(root)
        return max_path_sum
