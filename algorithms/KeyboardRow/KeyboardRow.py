class Solution(object):
    def findWords(self, words):
        line1, line2, line3 = set('qwertyuiop'), set('asdfghjkl'), set('zxcvbnm')
        res = []
        for word in words:
          w = set(word.lower())
          if w.issubset(line1) or w.issubset(line2) or w.issubset(line3):
            res.append(word)
        return res
