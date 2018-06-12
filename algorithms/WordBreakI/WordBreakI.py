class Solution(object):
    def wordBreak(self, s, wordDict):        
        wordSet = set(wordDict)
        n = len(s)
        dp = [False] * n
        
        for i in range(n):
            word = s[:i + 1]
            
            if word in wordSet:
                dp[i] = True
                continue
            
            for j in range(i):
                right = s[j + 1:i + 1]
                if dp[j] and right in wordDict:
                    dp[i] = True
                    break
        
        return dp[n - 1]

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
