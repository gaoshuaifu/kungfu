class Solution(object):
    def hammingDistance(self, x, y): 
        z = x ^ y
        c = 0
        while z > 0:
            c += 1
            z = z & (z - 1)
        return c
