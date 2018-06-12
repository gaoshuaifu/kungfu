class Solution(object):
    def findKth(self, nums1, nums2, k):
        n1, n2 = len(nums1), len(nums2)
        if n1 == 0:
            return nums2[k - 1]
        if n2 == 0:
            return nums1[k - 1]
        if k == 1:
            return min(nums1[0], nums2[0])
        
        k1, k2 = None, None
        if n1 < n2:
            k1 = min(k / 2, n1)
            k2 = k - k1
        else:
            k2 = min(k / 2, n2)
            k1 = k - k2
            
        if nums1[k1 - 1] < nums2[k2 - 1]:
            return self.findKth(nums1[k1:], nums2, k - k1)
        else:
            return self.findKth(nums1, nums2[k2:], k - k2)
        
    def findMedianSortedArrays(self, nums1, nums2):
        n1, n2 = len(nums1), len(nums2)
        n = n1 + n2
        
        if(n % 2):
            return self.findKth(nums1, nums2, (n + 1) / 2)
        else:
            return (self.findKth(nums1, nums2, n / 2) + self.findKth(nums1, nums2, n / 2 + 1)) / 2.0
