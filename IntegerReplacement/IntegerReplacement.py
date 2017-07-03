class Solution(object):
    def integerReplacement(self, n):
        res = 0
        while n > 1:
            if n % 2 == 0:
                n //= 2
            elif n % 4 == 1 or n == 3:
                n -= 1
            else:
                n += 1
            res += 1
        return res
