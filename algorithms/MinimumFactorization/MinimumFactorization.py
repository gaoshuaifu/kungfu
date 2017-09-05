class Solution(object):
    def smallestFactorization(self, a):
        if a == 1: return 1
        digits = []
        for i in range(2, 10)[::-1]:
            while a % i == 0:
                a /= i
                digits.append(str(i))
        digits.reverse()
        res = int("".join(digits)) if digits else 0
        return res if res <= (2 ** 31 - 1) and a == 1 else 0
