class Solution(object):
    DIR = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    def in_bound(self, matrix, i, j):
        return i >= 0 and i < len(matrix) and j >= 0 and j < len(matrix[0])

    def updateMatrix(self, matrix):
        m, n = len(matrix), len(matrix[0])
        res = [[0] * n for _ in range(m)]

        currQ = [(i, j) for i in range(m) for j in range(n) if matrix[i][j] == 0]
        visited = set(currQ)
        dist = 0
        while currQ:
            nextQ = []
            while currQ:
                i, j = currQ.pop(0)
                res[i][j] = dist
                for di, dj in Solution.DIR:
                    x, y = i + di, j + dj
                    if self.in_bound(matrix, x, y) and matrix[x][y] == 1 and (x, y) not in visited:
                        nextQ.append((x, y))
                        visited.add((x, y))
            currQ = nextQ
            dist += 1
        return res
