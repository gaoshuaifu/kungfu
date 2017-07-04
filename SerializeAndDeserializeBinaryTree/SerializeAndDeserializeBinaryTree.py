# DFS-based
class Codec:
    def _serializeHelper(self, root, vals):
        if not root:
            vals.append("#")
            return
        vals.append(str(root.val))
        self._serializeHelper(root.left, vals)
        self._serializeHelper(root.right, vals)

    # tree => string
    def serialize(self, root):
        vals = []
        self._serializeHelper(root, vals)
        return ",".join(vals)

    def _deserializeHelper(self, vals):
        val = next(vals)
        if val == "#":
            return None
        node = TreeNode(int(val))
        node.left = self._deserializeHelper(vals)
        node.right = self._deserializeHelper(vals)
        return node

    # string => tree
    def deserialize(self, data):
        vals = iter(data.split(","))
        root = self._deserializeHelper(vals)
        return root

# BFS-based
class Codec:

    def serialize(self, root):
        vals = []
        if not root:
            vals.append("#")
            return ",".join(vals)

        q = []
        q.append(root)
        while q:
            node = q.pop(0)
            if node:
                vals.append(str(node.val))
                q.append(node.left)
                q.append(node.right)
            else:
                vals.append("#")
        return ",".join(vals)

    def deserialize(self, data):
        vals = iter(data.split(","))
        val = next(vals)
        if val == "#":
            return None

        root = TreeNode(int(val))
        q = []
        q.append(root)
        while q:
            node = q.pop(0)
            val = next(vals)
            if val != "#":
                node.left = TreeNode(int(val))
                q.append(node.left)
            val = next(vals)
            if val != "#":
                node.right = TreeNode(int(val))
                q.append(node.right)
        return root
