class Solution(object):
    def findMaximumXOR(self, nums):
        max_xor, mask = 0, 0

        # i go through 31...1
        for i in range(31, -1, -1):
            mask = mask | (1 << i)
            prefixes = set()
            for num in nums:
                prefix = num & mask
                prefixes.add(prefix)

            xor = max_xor | (1 << i)

            # If xor ^ num1 == num2, then num1 ^ num2 == xor
            for prefix in prefixes:
                if (xor ^ prefix) in prefixes:
                    max_xor = xor
                    break

        return max_xor
