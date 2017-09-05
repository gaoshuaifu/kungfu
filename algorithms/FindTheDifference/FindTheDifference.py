class Solution(object):
    def findTheDifference(self, s, t):
        from collections import Counter
        cs = Counter(s)
        ct = Counter(t)
        return (ct - cs).keys()[0]
        
