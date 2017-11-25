class Term(object):
    def __init__(self, s):
        index = s.rfind("\t")
        self.level = index + 1
        self.len = len(s[index + 1:])
        self.is_file = "." in s


class Solution(object):
    def lengthLongestPath(self, input):
        terms = [Term(t) for t in input.split("\n")]
        stk, res = [], 0
        for term in terms:
            if stk and term.level < stk[-1].level + 1:
                if stk[-1].is_file:
                    res = max(res, sum([t.len for t in stk]) + len(stk) - 1)
                while stk and stk[-1].level >= term.level:
                    stk.pop()
            stk.append(term)
        if stk[-1].is_file:
            res = max(res, sum([term.len for term in stk]) + len(stk) - 1)
        return res
