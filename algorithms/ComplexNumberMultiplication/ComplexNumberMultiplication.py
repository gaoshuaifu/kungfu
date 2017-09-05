class Solution(object):
    def complexNumberMultiply(self, a, b):
        a1, a2 = map(int, a[:-1].split('+'))
        b1, b2 = map(int, b[:-1].split('+'))
        return '{}+{}i'.format(a1 * b1 - a2 * b2, a1 * b2 + a2 * b1)
