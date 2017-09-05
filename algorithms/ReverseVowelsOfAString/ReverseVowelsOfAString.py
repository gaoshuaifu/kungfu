class Solution(object):
    def is_vowel(self, c):
        return c in set(['a','e','i','o','u', 'A','E','I','O','U'])

    def reverseVowels(self, s):
        s = list(s)
        i, j = 0, len(s) - 1
        while i < j:
            while i < j and not self.is_vowel(s[i]):
                i += 1
            while i < j and not self.is_vowel(s[j]):
                j -= 1
            if i < j:
                s[i], s[j] = s[j], s[i]
                i += 1
                j -= 1
        return ''.join(s)
