class Solution(object):
    def fourSumCount(self, A, B, C, D):
        from collections import Counter
        AB = Counter([a + b for a in A for b in B])
        CD = Counter([-(c + d) for c in C for d in D])
        res = 0
        for k in AB.keys():
            if k in CD:
                res += AB[k] * CD[k]
        return res
