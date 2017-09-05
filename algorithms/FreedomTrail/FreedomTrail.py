# http://www.cnblogs.com/grandyang/p/6675879.html
class Solution(object):
    # when 12:00 direction points the ith position on the ring, and next move
    # the char at the jth position on key
    def helper(self, ring, key, indexes, i, j, cache):
        if j == len(key):
            return 0

        if (i, j) in cache:
            return  cache[(i, j)]

        min_steps = 0x7fffffff
        for k in indexes[key[j]]:
            step = min(abs(i - k), len(ring) - abs(i - k)) + 1
            min_steps = min(min_steps, step + self.helper(ring, key, indexes, k, j + 1, cache))
        cache[(i, j)] = min_steps
        return min_steps

    def findRotateSteps(self, ring, key):
        import collections
        indexes = collections.defaultdict(list)
        for i, c in enumerate(ring): indexes[c].append(i)
        return self.helper(ring, key, indexes, 0, 0, {})
