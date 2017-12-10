class Solution(object):
    def singleNumber(self, nums):
        xor = 0
        for num in nums:
            xor ^= num

        diff_bit = (xor & (xor - 1)) ^ xor

        a, b = 0, 0
        for num in nums:
            if num & diff_bit:
                a ^= num
            else:
                b ^= num
        return [a, b]
