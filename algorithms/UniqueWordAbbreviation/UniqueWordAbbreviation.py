class ValidWordAbbr(object):

    def __init__(self, dictionary):
        """
        :type dictionary: List[str]
        """
        from collections import defaultdict
        self.d = defaultdict(set)
        for word in dictionary:
            key = self.get_abbr(word)
            self.d[key].add(word)

    def get_abbr(self, word):
        n = len(word)
        if n <= 2:
            return word
        return word[0] + str(n - 2) + word[-1]

    def isUnique(self, word):
        """
        :type word: str
        :rtype: bool
        """

        key = self.get_abbr(word)
        return key not in self.d or (len(self.d[key]) == 1 and word in self.d[key])
