class Solution(object):
    def fractionAddition(self, expression):
        from fractions import Fraction
        fracs = map(
            Fraction,
            expression.replace("+", " +").replace("-", " -").split()
        )
        res = sum(fracs)
        return "{}/{}".format(res.numerator, res.denominator)

class Solution(object):
    def fractionAddition(self, expression):
        import fractions
        ints = map(int, re.findall('[+-]?\d+', expression))
        A, B, i = 0, 1, 0
        while i < len(ints):
            a, b = ints[i], ints[i + 1]
            A, B = A * b + a * B, B * b
            g = fractions.gcd(A, B)
            A //= g
            B //= g
            i += 2
        return "{}/{}".format(A, B)
