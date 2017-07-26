class Solution(object):
    def checkRecord(self, s):
        return len([x for x in s if x == 'A']) <= 1 and s.find('LLL') == -1
