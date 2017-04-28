
def find_nearest(points, k):
    heap = new MaxHeap()
    for point in points:
      d = point.x ^ 2 + point.y ^ 2 + point.z ^ 2
      if heap.size() < k:
        heap.insert(d, point)
      elif d < heap.maxKey():
        heap.removeMax()
        heap.insert(d, point)
    return heap.elements()
