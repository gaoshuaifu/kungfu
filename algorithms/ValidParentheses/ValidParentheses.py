class Solution(object):
    LEFT_OF = {
        ')':'(',
        ']':'[',
        '}':'{',
    }

    def isValid(self, s):
        stk = []
        for c in s:
            if c in "([{":
                stk.append(c)
            else:
                if stk and stk[-1] == self.LEFT_OF[c]:
                    stk.pop()
                else:
                    return False
        return len(stk) == 0
        
