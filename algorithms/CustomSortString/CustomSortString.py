class Solution(object):
    def customSortString(self, S, T):
        from collections import Counter
        counter = Counter(T)
        
        res = ""
        for c in S:
            if c in counter:
                count = counter.pop(c)
                res += c * count
            
        for c, count in counter.items():
            res += c * count

        return res
