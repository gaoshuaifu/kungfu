import copy
class Solution(object):
    def combineHelper(self, n, k, start):
        if len(self.sol) == k:
            self.res.append(copy.deepcopy(self.sol))
            return 
            
        # range of i: start <= i <= n
        for i in range(start, n + 1):
            self.sol.append(i)
            self.combineHelper(n, k, i + 1)
            self.sol.pop()
        
    def combine(self, n, k):
        self.res = []
        self.sol = []
        self.combineHelper(n, k, 1);
        return self.res
        
