class Solution(object):
    def wordPattern(self, p, s):
        words = s.split(" ")
        if len(p) != len(words):
            return False

        d1, d2 = {}, {}
        for c, w in zip(p, words):
            if c not in d1:
                d1[c] = w
            else:
                if w != d1[c]:
                    return False

            if w not in d2:
                d2[w] = c
            else:
                if c != d2[w]:
                    return False

        return True
