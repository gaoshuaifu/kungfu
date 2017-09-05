class Solution(object):
    def judgeSquareSum(self, c):
        i = 0
        while i * i <= c / 2:
            d = c - i * i
            if int(d ** 0.5) ** 2 == d:
                return True
            i += 1
        return False
