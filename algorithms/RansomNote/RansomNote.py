class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        from collections import Counter
        c1, c2 = Counter(ransomNote), Counter(magazine)
        for k in c1.keys():
            if c1[k] > c2[k]:
                return False
        return True
