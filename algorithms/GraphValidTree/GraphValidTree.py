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
        for n1, n2 in edges:
            graph[n1].append(n2)
            graph[n2].append(n1)

        visited = set()
        if not self.dfs(graph, visited, 0, -1):
            return False
        return len(visited) == n
