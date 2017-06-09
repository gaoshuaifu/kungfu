class Solution(object):
    def trailingZeroes(self, n):
        res = 0
        while n:
            res += n / 5
            n = n / 5
        return res
