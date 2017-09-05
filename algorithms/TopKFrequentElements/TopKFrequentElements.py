class Solution(object):
    def topKFrequent(self, nums, k):
        from collections import Counter
        counter = Counter(nums)
        return [k for k, v in counter.most_common(k)]
