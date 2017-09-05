class Solution(object):
    def helper(self, root, c):
        if not root:
            return 0
        s = root.val + self.helper(root.left, c) + self.helper(root.right, c)
        c[s] += 1
        return s

    def findFrequentTreeSum(self, root):
        if not root:
            return []
        from collections import Counter
        c = Counter()
        self.helper(root, c)
        m = max(c.values())
        return [k for k in c.keys() if c[k] == m]
