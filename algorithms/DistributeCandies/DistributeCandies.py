class Solution(object):
    def distributeCandies(self, candies):
        from collections import Counter
        c = Counter(candies)
        return min(len(c), len(candies) / 2)
