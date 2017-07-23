class Solution(object):
    def repeatedSubstringPattern(self, s):
        n = len(s)
        i = n / 2
        while i >= 1:
            if n % i == 0 and s[:i] * (n / i) == s:
                return True
            i -= 1
        return False
