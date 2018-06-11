class Solution(object):
    def partition(self, nums, low, high, pivot):
        i, j = low, high

        while i <= j:
            while i <= j and nums[i] <= pivot:
                if nums[i] == pivot:
                    pivot_index = i
                i += 1
            while i <= j and nums[j] > pivot:
                j -= 1

            if i <= j:
                nums[i], nums[j] = nums[j], nums[i]

        nums[pivot_index], nums[j] = nums[j], nums[pivot_index]

        return j

    def match_helper(self, nuts, bolts, low, high):
        if low >= high:
            return

        mid_bolts = self.partition(bolts, low, high, nuts[low])
        mid_nuts = self.partition(nuts, low, high, bolts[mid_bolts])

        assert mid_bolts == mid_nuts

        self.match_helper(nuts, bolts, low, mid_bolts - 1)
        self.match_helper(nuts, bolts, mid_bolts + 1, high)

    def match(self, nuts, bolts):
        assert len(nuts) == len(bolts)

        n = len(nuts)
        self.match_helper(nuts, bolts, 0, n - 1)

nuts = [5,3,2,4,6,1,7,9,8,0]
bolts = [7,4,1,8,5,2,9,6,3,0]
s = Solution()
s.match(nuts, bolts)
print(nuts)
print(bolts)
