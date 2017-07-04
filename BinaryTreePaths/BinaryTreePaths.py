class Solution(object):
    def binaryTreePathsHelper(self, root, sol, res):
        if not root.left and not root.right:
            res.append("->".join(map(str, sol)))
            return

        if root.left:
            sol.append(root.left.val)
            self.binaryTreePathsHelper(root.left, sol, res)
            sol.pop()
        if root.right:
            sol.append(root.right.val)
            self.binaryTreePathsHelper(root.right, sol, res)
            sol.pop()

    def binaryTreePaths(self, root):
        res, sol = [], []
        if not root:
            return res

        sol.append(root.val)
        self.binaryTreePathsHelper(root, sol, res)
        sol.pop()

        return res
