class Solution(object):
    def findRepeatedDnaSequences(self, s):
        import collections
        LEN = 10
        d = collections.defaultdict(int)
        for i in range(len(s) - LEN + 1):
            d[s[i:i+LEN]] += 1
        return [k for k, v in d.items() if v > 1]
