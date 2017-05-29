class Solution(object):
    def findRepeatedDnaSequences(self, s):
        import collections
        L = 10
        d = collections.defaultdict(int)
        for i in range(len(s) - L + 1):
            d[s[i:i+L]] += 1
        return [k for k, v in d.items() if v > 1]
