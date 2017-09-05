class Solution(object):
    def is_on_island(self, grid, i, j):
        return (i >= 0 and i < len(grid)) and (j >= 0 and j < len(grid[0])) and grid[i][j] == "1"

    def dfs(self, grid, i, j, visited):
        if not self.is_on_island(grid, i, j) or (i, j) in visited:
            return
        visited.add((i, j))
        self.dfs(grid, i + 1, j, visited)
        self.dfs(grid, i - 1, j, visited)
        self.dfs(grid, i, j + 1, visited)
        self.dfs(grid, i, j - 1, visited)


    def numIslands(self, grid):
        m = len(grid)
        if m == 0: return 0

        n = len(grid[0])
        if n == 0: return 0

        visited = set()
        num_islands = 0
        for i in range(m):
            for j in range(n):
                if self.is_on_island(grid, i, j) and (i, j) not in visited:
                    num_islands += 1
                    self.dfs(grid, i, j, visited)
        return num_islands
