class Solution(object):
  def josephus(self, n, k):
    if n == 1:
        return 1
    return (self.josephus(n - 1, k) + k - 1) % n + 1


s = Solution()
print s.josephus(10, 2)
