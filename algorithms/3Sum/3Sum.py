class Solution(object):
    def threeSum(self, nums):
        res = []
        n = len(nums)
        nums = sorted(nums)
        i = 0
        while i < n - 2:
            first = nums[i]
            j = i + 1
            k = n - 1
            while j < k:
                second = nums[j]
                third = nums[k]
                total = first + second + third
                if total == 0:
                    res.append((first, second, third))
                    while j < k and nums[j] == second:
                        j += 1
                    while j < k and nums[k] == third:
                        k -= 1
                elif total < 0:
                    while j < k and nums[j] == second:
                        j += 1
                else:
                    while j < k and nums[k] == third:
                        k -= 1
                while i < n - 2 and nums[i] == first:
                    i += 1
        res = [list(x) for x in set(res)]
        return res
        
