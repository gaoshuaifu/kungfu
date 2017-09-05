class Solution:
    def cloneGraphHelper(self, node, d):
        if node in d:
            return d[node]

        new_node = UndirectedGraphNode(node.label)
        d[node] = new_node
        for neighbor in node.neighbors:
            new_node.neighbors.append(self.cloneGraphHelper(neighbor, d))
        return new_node

    def cloneGraph(self, node):
        if not node: return None
        d = {}
        return self.cloneGraphHelper(node, d)
