class Solution(object):
    def verticalOrder(self, root):
        from collections import defaultdict

        buckets = defaultdict(list)
        queue = [(root, 0)]

        while queue:
            node, k = queue.pop(0)
            if node:
                buckets[k].append(node.val)
                queue.append((node.left, k - 1))
                queue.append((node.right, k + 1))

        return [buckets[k] for k in sorted(buckets.keys())]
