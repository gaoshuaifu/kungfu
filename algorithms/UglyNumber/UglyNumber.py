class Solution(object):
    def isUgly(self, num):
        if num == 0:
            return False
        for factor in [2, 3, 5]:
            while num % factor == 0:
                num = num / factor
        return num == 1
