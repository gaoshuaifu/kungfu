class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        import sys
        stk = []
        curr = root
        prev_val = -sys.maxint
        while curr or stk:
            if curr:
                stk.append(curr)
                curr = curr.left
            else:
                curr = stk.pop()
                if prev_val >= curr.val:
                    return False
                prev_val = curr.val
                curr = curr.right
        return True
