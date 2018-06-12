import copy
class Solution(object):
    def pathSumHelper(self, root, sum):
        if not root:
            return
        
        self.path.append(root.val)
        sum -= root.val
        
        if not root.left and not root.right:
            if sum == 0:
                self.res.append(copy.deepcopy(self.path))
            self.path.pop()
            return
        
        self.pathSumHelper(root.left, sum)
        self.pathSumHelper(root.right, sum)
        
        self.path.pop()
        
    def pathSum(self, root, sum):
        self.res = []
        self.path = []
        self.pathSumHelper(root, sum)
        return self.res
