class Solution(object):
    def countSubstrings(self, s):
        n, count = len(s), 0
        for k in range(n):
            for l in range(2):
                i, j = k, k + l
                while i >= 0 and j < n and s[i] == s[j]:
                    count += 1
                    i -= 1
                    j += 1
        return count
