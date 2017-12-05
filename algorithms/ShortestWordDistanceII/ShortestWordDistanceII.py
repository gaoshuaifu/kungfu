class WordDistance(object):
    def __init__(self, words):
        from collections import defaultdict
        self.d = defaultdict(list)
        for idx, word in enumerate(words):
            self.d[word].append(idx)

    def shortest(self, word1, word2):
        import itertools
        return min(
            [
                abs(a - b)
                for (a, b) in itertools.product(self.d[word1], self.d[word2])
            ]
        )
