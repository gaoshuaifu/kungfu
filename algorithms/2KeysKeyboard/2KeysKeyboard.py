class Solution(object):
    def minSteps(self, n):
        res, p = 0, 2
        while p * p <= n:
            while n % p == 0:
                res += p
                n = n / p
            p += 1
                
        if n > 1:
            res += n
        
        return res
