class Solution(object):
    def get_formulas(self, s):
        from itertools import product

        if s.count("+") + s.count("-") + s.count("*") == 0:
            return [s]

        formulas = []
        for i in range(len(s)):
            if s[i] in "+-*":
                left_formulas = self.get_formulas(s[:i])
                right_formulas = self.get_formulas(s[i + 1:])
                formulas.extend(
                    [
                        "(%s)%s(%s)" % (l, s[i], r)
                        for l, r in product(left_formulas, right_formulas)
                    ]
                )
        return formulas

    def diffWaysToCompute(self, s):
        formulas = self.get_formulas(s)
        return [eval(formula) for formula in formulas]
