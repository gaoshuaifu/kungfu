class Solution(object):
    def intersect(self, nums1, nums2):
        from collections import Counter
        counter1 = Counter(nums1)
        counter2 = Counter(nums2)
        return list((counter1 & counter2).elements())
