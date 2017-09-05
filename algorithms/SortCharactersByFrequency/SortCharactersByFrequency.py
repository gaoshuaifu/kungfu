class Solution(object):
    def frequencySort(self, s):
        from collections import Counter
        c = Counter(list(s))
        res = ""
        for k, v in sorted(c.items(), key=lambda x : x[1], reverse=True):
            res += k * v
        return res
