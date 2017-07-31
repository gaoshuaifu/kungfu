# DFS and cache/dp work together.
class Solution(object):
    DIRS = [(1,0),(-1,0),(0,1),(0,-1)]

    def in_bound(self, matrix, i, j):
        return i >= 0 and i < len(matrix) and j >= 0 and j < len(matrix[0])

    def dfs(self, matrix, i, j, cache):
        if cache[i][j] == 0:
            max_length = 1
            for di, dj in Solution.DIRS:
                x, y = i + di, j + dj
                if self.in_bound(matrix, x, y) and matrix[x][y] > matrix[i][j]:
                    length = 1 + self.dfs(matrix, x, y, cache)
                    max_length = max(max_length, length)
            cache[i][j] = max_length
        return cache[i][j]

    def longestIncreasingPath(self, matrix):
        if not matrix or not matrix[0]:
            return 0
        m, n = len(matrix), len(matrix[0])
        cache = [[0] * n for _ in range(m)]
        return max([self.dfs(matrix, i, j, cache) for i in range(m) for j in range(n)])


class Solution(object):
    def longestIncreasingPath(self, matrix):
        def dfs(i, j):
            if cache[i][j] == 0:
                val = matrix[i][j]
                cache[i][j] = 1 + max(
                    dfs(i - 1, j) if i - 1 >= 0 and val > matrix[i - 1][j] else 0,
                    dfs(i + 1, j) if i + 1 < m and val > matrix[i + 1][j] else 0,
                    dfs(i, j - 1) if j - 1 >= 0 and val > matrix[i][j - 1] else 0,
                    dfs(i, j + 1) if j + 1 < n and val > matrix[i][j + 1] else 0,
                )
            return cache[i][j]

        if not matrix or not matrix[0]:
            return 0
        m, n = len(matrix), len(matrix[0])
        cache = [[0] * n for _ in range(m)]
        return max([dfs(i, j) for i in range(m) for j in range(n)])
