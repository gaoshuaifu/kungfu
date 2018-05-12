class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        min_val = min(p.val, q.val)
        max_val = max(p.val, q.val)
        
        curr = root
        while curr:
            if curr.val > max_val:
                curr = curr.left
            elif curr.val < min_val:
                curr = curr.right
            else:
                return curr
        return None
