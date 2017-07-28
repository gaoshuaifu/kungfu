class Solution(object):
    def isUpperCase(self, c)
        return ord(c) >= ord("A") and ord(c) <= ord("Z")

    def detectCapitalUse(self, word):
        count = len([c for c in word if self.isUpperCase(c)])
        return count == len(word) or count == 0 or (count == 1 and self.isUpperCase(word[0]))
