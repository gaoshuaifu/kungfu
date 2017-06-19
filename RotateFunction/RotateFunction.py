class Solution(object):
    def maxRotateFunction(self, A):
        n, s = len(A), 0
        for i in range(n):
            s += i * A[i]
        sumA = sum(A)
        ms = s
        for num in A:
            s += n * num - sumA
            ms = max(ms, s)
        return ms
