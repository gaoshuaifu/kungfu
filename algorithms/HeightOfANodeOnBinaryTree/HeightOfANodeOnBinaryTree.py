class Solution:
  def get_height_helper(self, root, query):
    if not root:
        return None, False

    if root == query:
        return 1, True

    left_height, left_has_node = self.get_height_helper(root.left, query)
    right_height, right_has_node = self.get_height_right(root.right, query)
    
    if not left_has_node and not right_has_node:
        return None, False
    
    return left_height + 1 if left_has_node else right_height + 1


  def get_height(self, root, query):
    height, _ = self.get_height_helper(root, query)
    return height
