class Solution(object):
    def isAnagram(self, s, t):
        from collections import Counter
        sc, tc = Counter(s), Counter(t)
        return sc == tc
