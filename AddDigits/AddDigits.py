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
