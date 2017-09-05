class Solution(object):
    DIR = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    def in_bound(self, m, n, i, j):
        return i >= 0 and i < m and j >= 0 and j < n

    def dfs(self, m, n, N, i, j, cache):
        if not self.in_bound(m, n, i, j):
            return 1

        if N == 0: return 0

        if (N, i, j) in cache: return cache[(N, i, j)]

        count = 0
        for di, dj in Solution.DIR:
            x, y = i + di, j + dj
            count += self.dfs(m, n, N - 1, x, y, cache)

        cache[(N, i, j)] = count
        return count

    def findPaths(self, m, n, N, i, j):
        return self.dfs(m, n, N, i, j, {}) % (10 ** 9 + 7)
