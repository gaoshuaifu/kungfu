class Solution(object):
    def groupStrings(self, strings):
        from collections import defaultdict
        d = defaultdict(list)
        for s in strings:
            k = tuple(
                [
                    (ord(c) - ord(s[0]) + 26) % 26
                    for c in s
                ]
            )
            d[k].append(s)
        return d.values()
