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


class Solution(object):
    def validTree(self, n, edges):
        if len(edges) != n - 1:
            return False
        parent = range(n)
        def find(x):
            return x if parent[x] == x else find(parent[x])
        def union(xy):
            x, y = map(find, xy)
            parent[x] = y
            return x != y
        return all(map(union, edges))
