class Solution(object):
    def lengthOfLongestSubstring(self, s):
        from collections import defaultdict

        d = defaultdict(int)
        count = 0
        start, end = 0, 0
        max_len = 0

        while end < len(s):
            c1 = s[end]
            d[c1] += 1
            if d[c1] > 1:
                count += 1
            end += 1

            while count > 0:
                c2 = s[start]
                if d[c2] > 1:
                    count -= 1
                d[c2] -= 1
                start += 1

            max_len = max(max_len, end - start)

        return max_len
