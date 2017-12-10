class Solution(object):
    def dfs(self, graph, visited, node, parent):
        if node in visited:
            return False

        visited.add(node)

        for neighbor in graph[node]:
            if neighbor == parent:
                continue
            if self.dfs(graph, visited, neighbor, node) is False:
                return False
        return True

    def validTree(self, n, edges):
        if not edges:
            return n == 1

        from collections import defaultdict
        graph = defaultdict(list)
        for s, d in edges:
            graph[s].append(d)
            graph[d].append(s)

        visited = set()
        if not self.dfs(graph, visited, 0, -1):
            return False
        return len(visited) == n


class Solution(object):
    def validTree(self, n, edges):
        parent = range(n)
        for s, d in edges:
            while s != parent[s]:
                s = parent[s]
            while d != parent[d]:
                d = parent[d]
            if s == d:
                return False
            parent[s] = d
        return len(edges) == n - 1
