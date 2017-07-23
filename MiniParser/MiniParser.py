class Solution(object):
    def deserialize(self, s):
        if not s:
            return NestedInteger()

        if s[0] != '[':
            return NestedInteger(int(s))

        stk, i = [], 0
        for j in xrange(len(s)):
            if s[j] == '[':
                stk.append(NestedInteger()),
                i = j+1
            elif s[j] in ',]':
                if s[j-1].isdigit():
                    stk[-1].add(NestedInteger(int(s[i:j])))
                if s[j] == ']' and len(stk) > 1:
                    curr = stk.pop()
                    stk[-1].add(curr)
                i = j+1
        return stk[0]
