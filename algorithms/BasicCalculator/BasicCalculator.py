class Solution(object):
    def calculate(self, s):
        res, num, sign, stack = 0, 0, 1, []
        for c in s:
            if c.isdigit():
                num = 10 * num + int(c)
            elif c in ["-", "+"]:
                res += sign * num
                num = 0
                sign = [-1, 1][c == "+"]
            elif c == "(":
                # push res first, then sign into stack
                stack.append(res)
                stack.append(sign)
                sign, res = 1, 0
            elif c == ")":
                # the result inside the ()
                res += sign * num
                # the result inside the () with sign before the ()
                res *= stack.pop()
                # add it to the result outside the ()
                res += stack.pop()
                num = 0
        return res + num * sign
