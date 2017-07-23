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
