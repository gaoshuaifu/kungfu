class Solution(object):
    def numberOfArithmeticSlices(self, A):
        curr, res, n = 0, 0, len(A)
        for i in range(2, n):
            if A[i] - A[i - 1] == A[i - 1] - A[i - 2]:
                curr += 1
                res += curr
            else:
                curr = 0
        return res
