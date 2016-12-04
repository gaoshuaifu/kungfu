# www.geeksforgeeks.org/diameter-of-a-binary-tree

class Node:
  def __init__(self, value, left = None, right = None):
    self.value = value
    self.left = left
    self.right = right

# returns (longest_path, height)
def longestPath(node):
  if node == None:
    return 0, 0
  left_longest, left_height = longestPath(node.left)
  right_longest, right_height = longestPath(node.right)
  return max(left_longest, right_longest, left_height + right_height), max(left_height, right_height) + 1
