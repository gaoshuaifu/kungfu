class NumMatrix(object):
    def __init__(self, matrix):
        m = len(matrix)
        if m == 0: return

        n = len(matrix[0])
        if n == 0: return

        self.accu = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                self.accu[i][j] = self.accu[i-1][j] + self.accu[i][j-1] - self.accu[i-1][j-1] + matrix[i-1][j-1]

    def sumRegion(self, row1, col1, row2, col2):
        return self.accu[row2+1][col2+1] + self.accu[row1][col1] - self.accu[row2+1][col1] - self.accu[row1][col2+1]
