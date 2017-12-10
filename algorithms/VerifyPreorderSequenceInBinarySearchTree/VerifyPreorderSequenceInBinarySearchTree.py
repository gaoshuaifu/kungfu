class Solution(object):
    def verifyPreorder(self, preorder):
        import sys
        stack = []
        low = -sys.maxsize
        for p in preorder:
            if p < low:
                return False
            while stack and p > stack[-1]:
                low = stack.pop()
            stack.append(p)
        return True


class Solution1(object):
    def verifyPreorder(self, preorder):
        n = len(preorder)
        if n == 0 or n == 1:
            return True
        pivot, i = preorder[0], 1
        while i < len(preorder) and preorder[i] < pivot:
            i += 1
        return (i == n or all([x > pivot for x in preorder[i:]])) and \
            self.verifyPreorder(preorder[1:i]) and \
            self.verifyPreorder(preorder[i:])
