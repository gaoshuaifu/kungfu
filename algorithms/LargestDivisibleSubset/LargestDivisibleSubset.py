class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        d[k] is the largest subset with k as the largest element,
        i.e., the subset of all divisors of k in the input.
        With d[-1] = emptyset as useful base case.
        """

        d = {-1: set()}
        for num in sorted(nums):
            d[num] = max((d[k] for k in d if num % k == 0), key=len) | {num}
        return list(max(d.values(), key=len))
