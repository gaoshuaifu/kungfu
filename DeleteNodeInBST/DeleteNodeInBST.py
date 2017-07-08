class Solution(object):
    def deleteNode(self, root, key):
        if not root:
            return None

        if root.val > key:
            root.left = self.deleteNode(root.left, key)
        elif root.val < key:
            root.right = self.deleteNode(root.right, key)
        else: # when the current node is the one to delete
            if not root.left:
                return root.right
            elif not root.right:
                return root.left
            else: # when the node to delete has both left and right subtree
                # on the right tree, find the left most node with minimum value
                min_node = root.right
                while min_node.left:
                    min_node = min_node.left

                # assign the value of the min node to root
                root.val = min_node.val

                # delete the min node from the right subtree
                root.right = self.deleteNode(root.right, min_node.val)

        return root
