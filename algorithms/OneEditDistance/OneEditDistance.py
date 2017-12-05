class Solution(object):
    def isOneEditDistance(self, s, t):
        m, n = len(s), len(t)
        if abs(m - n) >= 2:
            return False

        i, j = 0, 0
        while i < m and j < n and s[i] == t[j]:
            i += 1
            j += 1

        if m > n:
            i += 1
        elif m == n:
            i += 1
            j += 1
        else:
            j += 1

        while i < m and j < n and s[i] == t[j]:
            i += 1
            j += 1

        return i == m and j == n
