class Solution(object):
    def largestValues(self, root):
        import sys

        res = []
        if not root:
            return res

        currQ = [root]
        while currQ:
            nextQ = []
            max_val = -sys.maxint
            while currQ:
                node = currQ.pop(0)
                max_val = max(max_val, node.val)
                if node.left:
                    nextQ.append(node.left)
                if node.right:
                    nextQ.append(node.right)
            res.append(max_val)
            currQ = nextQ

        return res
