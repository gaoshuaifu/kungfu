class Solution(object):
    def getHint(self, secret, guess):
        from collections import Counter
        sc, gc = Counter(secret), Counter(guess)
        a = sum([s == g for s, g in zip(secret, guess) if s == g])
        b = sum((sc & gc).values()) - a
        return '{}A{}B'.format(a, b)
