class Solution(object):
    def helper(self, n, m):
        if n == 0:
            return [""]
        if n == 1:
            return ["0", "1", "8"]

        res = []
        for s in self.helper(n - 2, m):
            if n != m:
                res.append("0" + s + "0")
            res.append("1" + s + "1")
            res.append("6" + s + "9")
            res.append("8" + s + "8")
            res.append("9" + s + "6")
        return res

    def findStrobogrammatic(self, n):
        return self.helper(n, n)
