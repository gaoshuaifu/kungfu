class Solution(object):
    def findAllConcatenatedWordsInADict(self, words):
        def is_cancat_word(word):
            if word in cache:
                return cache[word]

            for i in range(1, len(word)):
                if word[:i] in word_set and (word[i:] in word_set or is_cancat_word(word[i:])):
                    cache[word] = True
                    return True
            cache[word] = False
            return False

        word_set = set(words)
        cache = {}
        return [word for word in words if is_cancat_word(word)]
