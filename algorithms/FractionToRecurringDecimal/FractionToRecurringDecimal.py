class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        res = "-" if (numerator * denominator < 0) else ""
        numerator, denominator = abs(numerator), abs(denominator)

        div, remainder = divmod(numerator, denominator)
        res += str(div)
        if not remainder:
            return res

        res += "."

        # The dict keeps track of where (which index) a remainder has been seen.
        has_seen = {}
        while remainder and remainder not in has_seen:
            has_seen[remainder] = len(res)
            div, remainder = divmod(10 * remainder, denominator)
            res += str(div)

        if remainder in has_seen:
            index = has_seen[remainder]
            res = res[:index] + "(" + res[index:]
            res += ")"

        return res
