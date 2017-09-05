class Solution(object):
    def checkSubarraySum(self, nums, k):
        d = {0:-1}
        s = 0
        for i in range(len(nums)):
            s += nums[i]
            modk = s % k if k != 0 else s
            if modk in d:
                if i - d[modk] > 1:
                    return True
            else:
                d[modk] = i
        return False
