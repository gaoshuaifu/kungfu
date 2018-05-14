class Solution(object):
    def isBalancedHelper(self, root):
        if not root:
            return True, 0       
        left_is_balanced, left_height = self.isBalancedHelper(root.left)
        right_is_balanced, right_height = self.isBalancedHelper(root.right)
        return (
            left_is_balanced and right_is_balanced and abs(left_height - right_height) <= 1, 
            max(left_height, right_height) + 1,
        )
        
    def isBalanced(self, root):
        is_balanced, _ = self.isBalancedHelper(root)
        return is_balanced
