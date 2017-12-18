class Solution(object):
    def dfs(self, graph, visited, node):
        if node in visited:
            return

        visited.add(node)

        for neighbor in graph[node]:
            self.dfs(graph, visited, neighbor)

    def countComponents(self, n, edges):
        from collections import defaultdict

        graph = defaultdict(list)
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)

        count = 0
        visited = set()
        for node in range(n):
            if node not in visited:
                count += 1
                self.dfs(graph, visited, node)
        return count
