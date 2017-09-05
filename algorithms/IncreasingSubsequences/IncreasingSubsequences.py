class Solution(object):
    def findSubsequences(self, nums):
        S = set()
        for num in nums:
            T = set()
            for x in S:
                if x[-1] <= num:
                    T.add(x + tuple([num]))
            S = S.union(T)
            S.add(tuple([num]))
        return [list(x) for x in S if len(x) > 1]
