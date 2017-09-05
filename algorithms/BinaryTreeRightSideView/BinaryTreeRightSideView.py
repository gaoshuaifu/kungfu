class Solution(object):
    def rightSideView(self, root):
        res = []
        if root is None:
            return res

        currQ = []
        currQ.append(root)

        while currQ:
            res.append(currQ[0].val)
            nextQ = []
            while currQ:
                node = currQ.pop(0)
                if node.right:
                    nextQ.append(node.right)
                if node.left:
                    nextQ.append(node.left)
            currQ = nextQ
        return res
