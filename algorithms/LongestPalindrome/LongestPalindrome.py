class Solution(object):
    def longestPalindrome(self, s):
        from collections import Counter
        counter = Counter(s)
        length, has_odd = 0, False
        for v in counter.values():
            length += v - v % 2
            if v % 2:
                has_odd = True
        return length + 1 if has_odd else length
