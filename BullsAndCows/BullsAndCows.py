class Solution(object):
    def getHint(self, secret, guess):
        a = len([(s, g) for s, g in zip(secret, guess) if s == g])

        un_match_secret = [s for s, g in zip(secret, guess) if s != g]
        un_match_guess = [g for s, g in zip(secret, guess) if s != g] + list(guess[len(secret):])

        from collections import Counter
        secret_counter = Counter(un_match_secret)

        b = 0
        for g in un_match_guess:
            if g in secret_counter:
                b += 1
                secret_counter[g] -= 1
                if secret_counter[g] == 0:
                    del secret_counter[g]

        return '%sA%sB' % (a, b)
