class Solution(object):
    def get_height(self, tree, node, parent, cache):
        if (parent, node) in cache:
            return cache[(parent, node)]

        heights = [
            self.get_height(tree, child, node, cache) + 1
            for child in tree[node] if child != parent
        ]

        height = max(heights) if heights else 0
        cache[(parent, node)] = height
        return height

    def findMinHeightTrees(self, n, edges):
        if n == 0:
            return []

        # Create adjacency list to represent the tree
        from collections import defaultdict
        tree = defaultdict(list)
        for a, b in edges:
            tree[a].append(b)
            tree[b].append(a)

        # Take each node as the tree node, get the tree height
        heights, cache = {}, {}
        for root in range(n):
            heights[root] = self.get_height(tree, root, None, cache)

        # Return roots with min height
        min_height = min(heights.values())
        return [root for root, height in heights.items() if height == min_height]
