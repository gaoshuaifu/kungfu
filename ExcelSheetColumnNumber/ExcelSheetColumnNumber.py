class Solution(object):
    def titleToNumber(self, s):
        res = 0
        BASE = 26
        for i, c in enumerate(reversed(s)):
            res += (ord(c) - ord("A") + 1) * (BASE ** i)
        return res
