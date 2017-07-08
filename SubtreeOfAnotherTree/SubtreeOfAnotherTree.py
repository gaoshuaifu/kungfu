class Solution(object):
    def isSameTree(self, s, t):
        if not s and not t:
            return True

        if (s and not t) or (not s and t):
            return False

        if s.val != t.val:
            return False

        return self.isSameTree(s.left, t.left) and self.isSameTree(s.right, t.right)

    def isSubtree(self, s, t):
        if not s:
            return not t

        if self.isSameTree(s, t):
            return True

        return self.isSubtree(s.left, t) or self.isSubtree(s.right, t)
