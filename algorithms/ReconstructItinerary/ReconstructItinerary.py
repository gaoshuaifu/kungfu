class Solution(object):
    def dfs(self, city, graph, count, path):
        if all([v == 0 for v in count.values()]):
            return True

        if city not in graph:
            return False

        for neighbor in sorted(graph[city]):
            if count[(city, neighbor)] == 0:
                continue

            path.append(neighbor)
            count[(city, neighbor)] -= 1

            if self.dfs(neighbor, graph, count, path):
                return True

            path.pop()
            count[(city, neighbor)] += 1

        return False

    def findItinerary(self, tickets):
        import collections
        graph = collections.defaultdict(list)
        count = collections.defaultdict(int)
        for src, dst in tickets:
            graph[src].append(dst)
            count[(src, dst)] += 1

        path = ["JFK"]
        self.dfs("JFK", graph, count, path)
        return path
