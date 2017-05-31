class Solution(object):
    def intersection(self, nums1, nums2):
        from collections import Counter
        counter1 = Counter(nums1)
        counter2 = Counter(nums2)
        return (counter1 & counter2).keys()
