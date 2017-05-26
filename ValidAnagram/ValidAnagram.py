class Solution(object):
    def isAnagram(self, s, t):
        import collections

        d = collections.defaultdict(int)
        for c in s:
            d[c] += 1

        for c in t:
            if c not in d:
                return False
            d[c] -= 1
            if d[c] == 0:
                del d[c]

        return not d
