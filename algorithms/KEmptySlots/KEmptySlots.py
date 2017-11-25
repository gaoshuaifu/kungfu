class Solution(object):
    def kEmptySlots(self, flowers, k):
        import sys

        n = len(flowers)
        days = [None] * n
        for i, flower in enumerate(flowers):
            days[flower - 1] = i + 1

        i, left, right, res = 0, 0, k + 1, sys.maxsize
        while right < n:
            if days[i] < days[left] or days[i] <= days[right]:
                if i == right:
                    res = min(res, max(days[left], days[right]))
                left, right = i, i + k + 1
            i += 1
        return -1 if res == sys.maxsize else res
