class Solution(object):
    def _dedup(self, list_of_list):
        return map(list, set(map(tuple, map(sorted, list_of_list))))

    def fourSum(self, nums, target):
        from collections import defaultdict
        n = len(nums)
        d = defaultdict(list)
        for i in range(n):
            for j in range(i + 1, n):
                d[nums[i] + nums[j]].append((i, j))

        res = []
        for k in d.keys():
            if (target - k) in d:
                res.extend(
                    [
                        [nums[i], nums[j], nums[p], nums[q]]
                        for i, j in d[k] for p, q in d[target - k] if j < p
                    ]
                )
        return self._dedup(res)
