class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        positive = (numerator >= 0 and denominator >= 0) or (numerator <= 0 and denominator <= 0)
        res = "" if positive else "-"
        numerator, denominator = abs(numerator), abs(denominator)
        res += str(numerator / denominator)
        remaining = numerator % denominator
        if not remaining:
            return res
        has_seen = dict()
        digits = list()
        while remaining not in has_seen:
            digit = (10 * remaining) / denominator
            digits.append(str(digit))
            has_seen[remaining] = len(digits) - 1
            remaining = (10 * remaining) % denominator

        index = has_seen[remaining]
        res += "." + "".join(digits[:index])
        if not (index == len(digits) - 1 and digits[index] == '0'):
            res += "(" + "".join(digits[index:]) + ")"
        return res
