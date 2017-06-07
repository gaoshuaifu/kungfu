class Solution(object):
    def findMaxLength(self, nums):
        max_len = 0
        s = 0
        d = {0:0}

        # index start from 1
        for i, num in enumerate(nums, 1):
            if num == 0:
                s -= 1
            elif num == 1:
                s += 1
            if s in d:
                max_len = max(max_len, i - d[s])
            else:
                d[s] = i
        return max_len
