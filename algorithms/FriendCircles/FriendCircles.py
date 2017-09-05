# M is an adjacency matrix of friendship
class Solution(object):
    def dfs(self, M, i, visited):
        if i in visited: return
        visited.add(i)
        for j in [j for j, v in enumerate(M[i]) if v == 1]:
            self.dfs(M, j, visited)

    def findCircleNum(self, M):
        if not M: return 0
        count, visited = 0, set()
        for i in range(len(M)):
            if i not in visited:
                count += 1
                self.dfs(M, i, visited)
        return count
