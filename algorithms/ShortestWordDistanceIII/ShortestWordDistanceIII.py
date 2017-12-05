class Solution(object):
    def shortestWordDistance(self, words, word1, word2):
        from collections import defaultdict
        d = defaultdict(list)
        for idx, word in enumerate(words):
            d[word].append(idx)

        import itertools
        return min(
            [
                abs(a - b)
                for (a, b) in itertools.product(d[word1], d[word2]) if a != b
            ]
        )
