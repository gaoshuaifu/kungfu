class Solution(object):
    def shortestDistance(self, words, word1, word2):
        for d in range(1, len(words)):
            for i in range(len(words) - d):
                if (words[i] == word1 and words[i + d] == word2) or \
                   (words[i] == word2 and words[i + d] == word1):
                    return d
