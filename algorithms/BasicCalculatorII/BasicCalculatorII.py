class Solution(object):
    def calculate(self, s):
        import re

        # Parse the expression
        # re.findall('\d+|\S', '-1 + 2 * 3') => ['-', '1', '+', '2', '*', '3']
        tokens = iter(re.findall('\d+|\S', s))

        total, curr_term, sign = 0, 0, 1
        for token in tokens:
            if token in '+-':
                total += sign * curr_term
                sign = 1 if token == '+' else -1
            elif token in '*/':
                next_term = int(next(tokens))
                curr_term = curr_term * next_term if token == '*' else curr_term / next_term
            else:
                curr_term = int(token)
        total += sign * curr_term
        return total


class Solution(object):
    def calculate(self, s):
        s = s.replace(' ', '')
        n, stk, sign, num = len(s), [], '+', 0
        for i in xrange(n):
            if s[i].isdigit():
                num = 10 * num + ord(s[i]) - ord('0')
            if not s[i].isdigit() or i == n - 1:
                if sign == '+':
                    stk.append(num)
                elif sign == '-':
                    stk.append(-num)
                elif sign == '*':
                    stk[-1] = stk[-1] * num
                else:
                    tmp = stk[-1] / num
                    stk[-1] = tmp if tmp > 0 else -(abs(stk[-1]) / abs(num))
                sign = s[i]
                num = 0
        return sum(stk)
