class Solution(object):
    def findAnagrams(self, s, p):
        from collections import defaultdict

        d = defaultdict(int)
        for c in p:
            d[c] += 1

        count = len(d)
        start, end = 0, 0
        res = []

        while end < len(s):
            c1 = s[end]
            if c1 in d:
                d[c1] -= 1
                if d[c1] == 0:
                    count -= 1
            end += 1

            while count == 0:
                c2 = s[start]
                if c2 in d:
                    d[c2] += 1
                    if d[c2] > 0:
                        count += 1
                if end - start == len(p):
                    res.append(start)
                start += 1

        return res
