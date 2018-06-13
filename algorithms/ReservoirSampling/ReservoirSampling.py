class Solution(object):
    def sample(self, n, k):
        import random

        # init 0...(k-1)
        res = range(k)

        # go through k...(n-1)
        for i in range(k, n):
            # get a random number between 0...i
            r = random.randint(0, i)
            if r < k:
                res[r] = i

        return res

s = Solution()
print(s.sample(10, 3))
