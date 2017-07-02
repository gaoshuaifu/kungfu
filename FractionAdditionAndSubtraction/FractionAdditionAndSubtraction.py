class Solution(object):
    def fractionAddition(self, expression):
        from fractions import Fraction
        fracs = map(
            Fraction,
            expression.replace("+", " +").replace("-", " -").split()
        )
        res = sum(fracs)
        return "{}/{}".format(res.numerator, res.denominator)
