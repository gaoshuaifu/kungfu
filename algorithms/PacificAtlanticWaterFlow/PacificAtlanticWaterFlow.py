class Solution(object):
    DIRS = [(1,0),(-1,0),(0,1),(0,-1)]

    def in_bound(self, matrix, i, j):
        return i >= 0 and i < len(matrix) and j >= 0 and j < len(matrix[0])

    def dfs(self, matrix, i, j, visited):
        visited[i][j] = True
        for di, dj in Solution.DIRS:
            x, y = i + di, j + dj
            if self.in_bound(matrix, x, y) and not visited[x][y] and matrix[x][y] >= matrix[i][j]:
                self.dfs(matrix, x, y, visited)

    def pacificAtlantic(self, matrix):
        if not matrix or not matrix[0]:
            return []
        m, n = len(matrix), len(matrix[0])

        visited_p = [[False] * n for _ in range(m)]
        visited_a = [[False] * n for _ in range(m)]

        for i in range(m):
            self.dfs(matrix, i, 0, visited_p)
            self.dfs(matrix, i, n - 1, visited_a)

        for j in range(n):
            self.dfs(matrix, 0, j, visited_p)
            self.dfs(matrix, m - 1, j, visited_a)
        return [[i, j] for i in range(m) for j in range(n) if visited_p[i][j] and visited_a[i][j]]
