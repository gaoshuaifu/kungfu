class Codec:
    def _serializeHelper(self, node, vals):
        if not node:
            return
        vals.append(str(node.val))
        self._serializeHelper(node.left, vals)
        self._serializeHelper(node.right, vals)

    def serialize(self, root):
        vals = []
        self._serializeHelper(root, vals)
        return " ".join(vals)

    def _deserializeHelper(self, min_val, max_val, vals):
        if not vals:
            return None
        val = int(vals[0])
        if min_val < val and val < max_val:
            node = TreeNode(val)
            vals.pop(0)
            node.left = self._deserializeHelper(min_val, val, vals)
            node.right = self._deserializeHelper(val, max_val, vals)
            return node

    def deserialize(self, data):
        import sys
        vals = data.split()
        root = self._deserializeHelper(-sys.maxint, sys.maxint, vals)
        return root
