class Solution(object):
    def clone(self, t):
        if not t:
            return None
        r = TreeNode(t.val)
        r.left = self.clone(t.left)
        r.right = self.clone(t.right)
        return r

    def mergeTrees(self, t1, t2):
        if not t1 and not t2:
            return None

        if t1 and not t2:
            return self.clone(t1)

        if not t1 and t2:
            return self.clone(t2)

        # when t1 and t2 overlap
        t = TreeNode(t1.val + t2.val)
        t.left = self.mergeTrees(t1.left, t2.left)
        t.right = self.mergeTrees(t1.right, t2.right)
        return t
