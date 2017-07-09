class Solution(object):
    def process_clause(self, clause):
        if clause[0] == "x":
            clause = "+" + clause
        terms = clause.replace("+x", "+1x").replace("-x", "-1x").\
            replace("+", " +").replace("-", " -").split()
        coef = sum([int(term[:-1]) for term in terms if term.endswith("x")])
        const= sum([int(term) for term in terms if not term.endswith("x")])
        return coef, const

    def solveEquation(self, equation):
        left_clause, right_clause = equation.split("=")
        left_coef, left_const = self.process_clause(left_clause)
        right_coef, right_const = self.process_clause(right_clause)
        coef = left_coef - right_coef
        const = right_const - left_const
        if coef == 0:
            return "Infinite solutions" if const == 0 else "No solution"
        else:
            return "x=%s" % (const / coef)
