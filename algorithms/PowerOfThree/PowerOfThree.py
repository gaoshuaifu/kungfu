class Solution(object):
    def isPowerOfThree(self, n):
        if n <= 0:
            return False
        import math
        coef = int(math.log(n, 3))
        # math.log(243, 3) = 4.999999999 instead of 5.0
        return math.pow(3, coef) == n or math.pow(3, coef + 1) == n
