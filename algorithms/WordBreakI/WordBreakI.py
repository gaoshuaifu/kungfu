class Solution(object):
    def wordBreakHelper(self, s, wordSet, start, cache):
        if start == len(s):
            return True
        
        if start in cache:
            return cache[start]
        
        for end in range(start + 1, len(s) + 1):
            if s[start:end] in wordSet and self.wordBreakHelper(s, wordSet, end, cache):
                cache[start] = True 
                return True
         
        cache[start] = False
        return False
            
        
    def wordBreak(self, s, wordDict):
        return self.wordBreakHelper(s, set(wordDict), 0, {})
