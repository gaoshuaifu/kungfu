class Solution(object):
    def lengthOfLongestSubstringKDistinct(self, s, k):
        from collections import defaultdict

        start, end, uniq, counter, max_len = 0, 0, 0, defaultdict(int), 0
        while end < len(s):
            counter[s[end]] += 1

            if counter[s[end]] == 1:
                uniq += 1

            if uniq == k + 1:
                max_len = max(max_len, end - start)

            while uniq == k + 1:
                counter[s[start]] -= 1
                if counter[s[start]] == 0:
                    uniq -= 1
                start += 1

            end += 1

        max_len = max(max_len, end - start)

        return max_len
