class Solution(object):
    def addStrings(self, num1, num2):
        i, j = len(num1) - 1, len(num2) - 1
        carry, res = 0, []
        while i >= 0 or j >= 0:
            s = 0
            if i >= 0:
                s += int(num1[i])
                i -= 1
            if j >= 0:
                s += int(num2[j])
                j -= 1
            s += carry
            digit = s % 10
            carry = s / 10
            res.append(digit)
        if carry:
            res.append(carry)
        return "".join(map(str, res[::-1]))
