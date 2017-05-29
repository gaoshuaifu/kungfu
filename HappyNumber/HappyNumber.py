class Solution(object):
    # Pass an integer to a list of digits.
    def _parse(self, n):
        digits = []
        while n > 0:
            n, r = divmod(n, 10)
            digits.append(r)
        return digits

    def isHappy(self, n):
        seen = set()
        while True:
            # Computer sum of squares of digits.
            n = sum(map(lambda x: x * x, self._parse(n)))

            # If it is 1, then happy.
            if n == 1:
                return True

            # If it is seen before, then not happy.
            if n in seen:
                return False

            seen.add(n)
