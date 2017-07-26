class Solution(object):
    def nextGreaterElement(self, n):
        s = list(str(n))

        i = len(s) - 2
        while i >= 0 and s[i] >= s[i + 1]:
            i -= 1

        if i < 0:
            return -1

        j = len(s) - 1
        while j > i and s[j] <= s[i]:
            j -= 1

        s[i], s[j] = s[j], s[i]
        s = s[:i + 1] + s[len(s) - 1: i :-1]
        res = int(''.join(s))
        return res if res <= (2**31-1) else -1
