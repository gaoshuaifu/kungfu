class Solution(object):
    def levelOrder(self, root):
        res = []
        if not root:
            return res
        
        currQ = []
        currQ.append(root)
        
        while currQ:
            level_nodes = []
            nextQ = []
            while currQ:
                node = currQ.pop(0)
                level_nodes.append(node.val)
                if node.left:
                    nextQ.append(node.left)
                if node.right:
                    nextQ.append(node.right)
            currQ = nextQ
            res.append(level_nodes)
        return res
                
        
