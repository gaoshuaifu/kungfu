class Solution(object):
    def maxProduct(self, words):
        from collections import defaultdict
        d = defaultdict(int)
        for word in words:
            mask = 0
            for c in set(word):
                mask |= 1 << (ord(c) - ord("a"))
            d[mask] = max(d[mask], len(word))
        return max([d[mask1] * d[mask2] for mask1 in d for mask2 in d if mask1 & mask2 == 0] + [0])
