class Solution(object):
    def addStrings(self, num1, num2):
        i, j = len(num1) - 1, len(num2) - 1
        carry, res = 0, []
        while i >= 0 or j >= 0:
            s = 0
            if i >= 0:
                s += num1[i]
            if j >= 0:
                s += num2[j]
            s += carry
            digit = s % 10
            carry = s / 10
            res.append(digit)
        if carry:
            res.append(carry)
        return "".join(map(str, ))
