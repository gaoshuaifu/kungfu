class Solution(object):
    def wordPattern(self, p, s):
        words = s.split(" ")
        if len(p) != len(words):
            return False

        # char and word have to have 1-to-1 relationship
        d1, d2 = {}, {}
        for c, w in zip(p, words):
            # when chars are the same, the corresponding words should be the same
            if c not in d1:
                d1[c] = w
            else:
                if w != d1[c]:
                    return False

            # when words are the same, the corresponding chars should be the same
            if w not in d2:
                d2[w] = c
            else:
                if c != d2[w]:
                    return False

        return True
