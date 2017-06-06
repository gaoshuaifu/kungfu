class Solution(object):
    def minWindow(self, s, t):
        from collections import defaultdict
        import sys

        # save the freq of each char in t, it is a histogram
        d = defaultdict(int)
        for c in t:
            d[c] += 1

        # the number of chars need to find
        count = len(d)

        start, end = 0, 0
        min_len = sys.maxint
        min_str = ""

        while end < len(s):
            c = s[end]
            if c in d:
                d[c] -= 1
                if d[c] == 0:
                    count -=1
            end += 1

            # nothing to find because we've found everything needed
            while count == 0:
                tmpc = s[start]
                if tmpc in d:
                    d[tmpc] += 1
                    if d[tmpc] > 0:
                        count += 1
                if end - start < min_len:
                    min_len = end - start
                    min_str = s[start:end]
                start +=1

        return min_str
