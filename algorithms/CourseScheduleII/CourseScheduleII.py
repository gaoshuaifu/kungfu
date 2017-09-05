# Topological Sort with loop checking.
class Solution(object):
    WHITE, GRAY, BLACK = 0, 1, 2

    def dfs(self, node, graph, color, path):
        if color[node] == Solution.GRAY:
            return False
        if color[node] == Solution.BLACK:
            return True

        color[node] = Solution.GRAY

        for neighbor in graph[node]:
            if not self.dfs(neighbor, graph, color, path):
                return False

        color[node] = Solution.BLACK
        path.append(node)

        return True

    def findOrder(self, numCourses, prerequisites):
        graph = {node:[] for node in range(numCourses)}
        for p in prerequisites:
            graph[p[1]].append(p[0])

        color, path = {node:Solution.WHITE for node in range(numCourses)}, []
        for node in range(numCourses):
            if color[node] == Solution.WHITE:
                if not self.dfs(node, graph, color, path):
                    return []
        return path[::-1]
