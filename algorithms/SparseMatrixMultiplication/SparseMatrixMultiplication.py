class Solution(object):
    def multiply(self, A, B):
        m = len(A)
        n = len(A[0])
        l = len(B[0])

        # C dimension (m x l)
        C = [[0] * l for _ in range(m)]

        for i in range(m):
            for j in range(n):
                # A is sparse, so skip a lot of computation
                if A[i][j]:
                    for k in range(l):
                        C[i][k] += A[i][j] * B[j][k]
        return C
