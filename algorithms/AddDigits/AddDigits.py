class Solution(object):
    def _parse(self, n):
        ds = []
        while n:
            n, d = divmod(n, 10)
            ds.append(d)
        return ds

    def addDigits(self, num):
        while num > 9:
            ds = self._parse(num)
            num = sum(ds)
        return num

# https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
class Solution(object):
    def addDigits(self, num):
        return 0 if num == 0 else (num - 1) % 9 + 1
