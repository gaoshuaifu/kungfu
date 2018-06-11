class Solution(object):
    def find(self, nums):
        n = len(nums)
        res = [None] * n
        stk = []

        for i in range(n - 1, -1, -1):
            while stk and stk[-1] <= nums[i]:
                stk.pop()
            res[i] = stk[-1] if stk else None
            stk.append(nums[i])

        return res


s = Solution()
print(s.find([2, 3, 4, 1, 5]))
