class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        res = "-" if (numerator * denominator < 0) else ""
        numerator, denominator = abs(numerator), abs(denominator)
        div, remainder = divmod(numerator, denominator)
        res += str(div)
        if not remainder:
            return res

        has_seen = {}
        digits = []
        while remainder not in has_seen:
            has_seen[remainder] = len(digits)
            digit, remainder = divmod(10 * remainder, denominator)
            digits.append(str(digit))

        if digits[-1] == "0":
            digits.pop()

        index = has_seen[remainder]
        res += "." + "".join(digits[:index])
        if index != len(digits):
            res += "(" + "".join(digits[index:]) + ")"
        return res
