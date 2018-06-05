class Solution(object):
  def sort(self, A):
    return sorted(A, cmp=lambda x, y : -1 if str(x) < str(y) else 1)

s = Solution()
print(s.sort(range(100)))
