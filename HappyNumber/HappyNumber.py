class Solution(object):
    def _parse(self, n):
        digits = []
        while n > 0:
            n, r = divmod(n, 10)
            digits.append(r)
        return digits

    def isHappy(self, n):
        seen = set()
        while True:
            n = sum(map(lambda x: x * x, self._parse(n)))
            if n == 1:
                return True
            if n in seen:
                return False
            seen.add(n)
