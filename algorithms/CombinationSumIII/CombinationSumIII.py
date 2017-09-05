class Solution(object):
    def combinationSum3(self, k, n):
        import itertools
        res = []
        for comb in itertools.combinations(range(1, 10), k):
            if sum(comb) == n:
                res.append(list(comb))
        return res
