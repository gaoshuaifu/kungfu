class Solution(object): 
    MAP = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz",
    }

    def helper(self, digits, index, sol, res):
        if index == len(digits):
            res.append("".join(sol))
            return
        
        for c in list(self.MAP[digits[index]]):
            sol.append(c)
            self.helper(digits, index + 1, sol, res)
            sol.pop()
            
        
    def letterCombinations(self, digits):
        if not digits:
            return []
        
        res, sol = [], []
        self.helper(digits, 0, sol, res)
        return res
        
