class Solution(object):
    def helper(self, left, right, sol):
        if left == 0 and right == 0:
            self.res.append(sol)
            return
        
        if left > 0:
            self.helper(left - 1, right, sol + "(")
            
        if left < right:
            self.helper(left, right - 1, sol + ")")

        
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        self.res = []
        self.helper(n, n, "")
        return self.res
