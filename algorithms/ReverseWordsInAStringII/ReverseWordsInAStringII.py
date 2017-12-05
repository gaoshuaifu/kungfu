class Solution(object):
    def reverseWords(self, s):
        """
        :type s: a list of 1 length strings (List[str])
        :rtype: nothing
        """

        def reverse(s, start, end):
            for i in range((end - start) / 2):
                s[start + i], s[end - 1 - i] = s[end - 1 - i], s[start + i]

        i, j = 0, 0
        while j <= len(s):
            if j == len(s) or s[j] == ' ':
                reverse(s, i, j)
                i = j + 1
            j += 1
        reverse(s, 0, len(s))
