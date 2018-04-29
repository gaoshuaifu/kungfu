class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        wordSet = set(wordList)
        
        dist = 1
        currQ = []
        visited = set()
        currQ.append(beginWord)
        visited.add(beginWord)
        
        while currQ:
            nextQ = []
            while currQ:
                currWord = currQ.pop(0)
                if currWord == endWord:
                    return dist
                for i in range(len(currWord)):
                    for j in range(26):
                        nextWord = currWord[:i] + chr(ord("a") + j) + currWord[i+1:]
                        if currWord != nextWord and nextWord in wordSet and nextWord not in visited:
                            nextQ.append(nextWord)
                            visited.add(nextWord)
            currQ = nextQ
            dist += 1
        return 0
